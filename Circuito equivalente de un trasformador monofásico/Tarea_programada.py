#__________________________________________________________________________________________________#
#Estudiante: Jose Mario Navarro Bejarano
#Carné: B75398
#Descripción: Este programa se encarga de realizar el calculo de los componentes del
#   circuito equivalente de un transformador monofásico. Para su utilización tomar
#   en cuenta los siguientes puntos:
#       1- El programa se puede ejecutar desde algun IDE que permita ejecutar código de
#           de python. Puede utilizarse Visual Studio Code.
#       2- Para ejecutarse se requieren los paquetes tkinter y math.
#       3- Esta versión de este programa no considera efectos de frecuencia.
#       4- IMPORTANTE: Esta versión unicamente realiza el cálculo correctamente cuando los valores
#           para Circuito abierto son medidos en Baja Tensión y los valores de 
#           Cortocircuito se miden en Alta Tensión.
#       5- El programa se puede utilizar para transformadores elevadores o reductores.
#___________________________________________________________________________________________________#
import tkinter as tk
import math

#Variables
size = (1200,600) #Tamaño de la ventana

Xu= 0
Rfe= 0
Rcc= 0
Xcc= 0
vprim=0
vsec=0


#colores
gray = (104,104,104) 
blue1= (51, 161, 246)
white= (255, 255, 255)
black= (0,0,0)
texto= ""


def obtener_texto():
    #Lectura de los datos obtenidos
    dato_v_cortocircuito=v_cortocircuito.get()
    dato_A_cortocircuito=A_cortocircuito.get()
    dato_P_cortocircuito=P_cortocircuito.get()
    
    dato_v_circuito_abierto=v_circuito_abierto.get()
    dato_A_circuito_abierto=A_circuito_abierto.get()
    dato_P_circuito_abierto=P_circuito_abierto.get()
    
    dato_s_aparente=S_aparente.get()
    dato_r_transformacion=r_transformacion.get()
    
    try:
        #pasar datos a numeros
        dato_v_cortocircuito=float(dato_v_cortocircuito)
        dato_A_cortocircuito=float(dato_A_cortocircuito)
        dato_P_cortocircuito=float(dato_P_cortocircuito)
        dato_v_circuito_abierto=float(dato_v_circuito_abierto)
        dato_A_circuito_abierto=float(dato_A_circuito_abierto)
        dato_P_circuito_abierto=float(dato_P_circuito_abierto)
        dato_s_aparente=float(dato_s_aparente)
        dato_r_transformacion=float(dato_r_transformacion)
        ######################################################################revisar primario y secundario
        #pasar datos de secundario a primario
        print(dato_r_transformacion)
        if dato_r_transformacion < 1:
            dato_v_cortocircuito=dato_v_cortocircuito*dato_r_transformacion
            dato_A_cortocircuito=dato_A_cortocircuito*(1/dato_r_transformacion)
            print(1)
        else:
            dato_v_circuito_abierto=dato_v_circuito_abierto*dato_r_transformacion
            dato_A_circuito_abierto=dato_A_circuito_abierto*(1/dato_r_transformacion)
            print(2)            
        #Calculo de los parámetros
        global Xu 
        Xu = (pow(dato_v_circuito_abierto,2))/math.sqrt(pow((dato_v_circuito_abierto*dato_A_circuito_abierto),2)-pow(dato_P_circuito_abierto,2))
        Xu=round(Xu,4)
        global Rfe 
        Rfe = pow(dato_v_circuito_abierto,2)/(dato_P_circuito_abierto)
        Rfe=round(Rfe,4)
        global Rcc 
        Rcc = (dato_P_cortocircuito)/(pow(dato_A_cortocircuito,2))
        Rcc=round(Rcc,4)
        global Xcc 
        Xcc = (dato_v_cortocircuito*dato_A_cortocircuito*math.sin(math.acos((dato_P_cortocircuito)/(dato_v_cortocircuito*dato_A_cortocircuito))))/(pow(dato_A_cortocircuito,2))
        Xcc=round(Xcc,4)
        global vprim
        vprim = dato_v_circuito_abierto
        vprim=round(vprim,4)
        global  vsec
        vsec = dato_v_circuito_abierto*(1/dato_r_transformacion)
        vsec=round(vsec,4)
    except Exception as e:
        print("Alguno de los valores ingresados no son correctos \n")
        print(e)
        ejecutar()

    window.destroy()
    equivalente()
    
def ejecutar():
    #loop principal
    window.mainloop()
    
    
def equivalente():
    #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
    #Configuracion de la ventana de circuito equivalente
    
    window_equiv=tk.Tk()
    window_equiv.geometry("683x320")
    window_equiv.resizable(False, False)
    window_equiv.config(background="white")
    window_equiv.title("Circuito equivalente")

    #Obtener imagen de fondo
    imagen=tk.PhotoImage(file="circuito_equivalente.png")
    label_img_fondo_equiv = tk.Label(window_equiv, image=imagen)
    label_img_fondo_equiv.pack()
    label_img_fondo_equiv.place(x=0, y=0)

    
    #Colocar datos de circuito equivalente
    label_R1 = tk.Label(window_equiv, text=str(Rcc/2),fg="black", bg="white")
    label_R1.pack()
    label_R1.place(x=145, y=50)
    
    label_X1 = tk.Label(window_equiv, text=str(Xcc/2),fg="black", bg="white")
    label_X1.pack()
    label_X1.place(x=238, y=50)
    
    label_R2_prim = tk.Label(window_equiv, text=str(Rcc/2),fg="black", bg="white")
    label_R2_prim.pack()
    label_R2_prim.place(x=387, y=50)
    
    label_X2_prim = tk.Label(window_equiv, text=str(Xcc/2),fg="black", bg="white")
    label_X2_prim.pack()
    label_X2_prim.place(x=476, y=50)
    
    label_v_prima = tk.Label(window_equiv, text=str(vprim),fg="black", bg="white")
    label_v_prima.pack()
    label_v_prima.place(x=16, y=154)
    
    label_v_secu = tk.Label(window_equiv, text=str(vsec),fg="black", bg="white")
    label_v_secu.pack()
    label_v_secu.place(x=637, y=154)
    
    label_Rfe = tk.Label(window_equiv, text=str(Rfe),fg="black", bg="white")
    label_Rfe.pack()
    label_Rfe.place(x=206, y=163)
    
    label_Xu = tk.Label(window_equiv, text=str(Xu),fg="black", bg="white")
    label_Xu.pack()
    label_Xu.place(x=426, y=167)
    
    #Loop de venta de circuito equivalente
    window_equiv.mainloop()
    

if __name__ == "__main__":
    #Configuracion de la ventana principal
    window=tk.Tk()
    window.geometry("1200x600")
    window.title("Ingresar resultados de pruebas")
    window.resizable(False, False)
    window.config(background="white")

    #Obtener imagen de fondo
    imagen_fondo=tk.PhotoImage(file="Fondo.png")
    label_img_fondo = tk.Label(window, image=imagen_fondo)
    label_img_fondo.pack()
    label_img_fondo.place(x=0, y=0)
    
    #Cargar imagen de cortocircuito
    imagen_cortocircuito=tk.PhotoImage(file="circuito_p_cortocircuito.png")
    label_img_cortocircuito = tk.Label(window, image=imagen_cortocircuito)
    label_img_cortocircuito.pack()
    label_img_cortocircuito.place(x=60, y=70)
    
    #Cargar imagen de circuito abierto
    imagen_circuito_abierto=tk.PhotoImage(file="circuito_p_circuito_abierto.png")
    label_img_circuito_abierto = tk.Label(window, image=imagen_circuito_abierto)
    label_img_circuito_abierto.pack()
    label_img_circuito_abierto.place(x=645, y=70)

    #Cuadros de texto para ingresar datos
    #V cortocircuito
    v_cortocircuito = tk.Entry(window)
    v_cortocircuito.pack()
    v_cortocircuito.place(x=451, y=385)
    
    #A cortocircuito
    A_cortocircuito = tk.Entry(window)
    A_cortocircuito.pack()
    A_cortocircuito.place(x=452, y=420)    

    #P cortocircuito
    P_cortocircuito = tk.Entry(window)
    P_cortocircuito.pack()
    P_cortocircuito.place(x=452, y=460)
    
    #V circuito abierto
    v_circuito_abierto = tk.Entry(window)
    v_circuito_abierto.pack()
    v_circuito_abierto.place(x=1026, y=385)
    
    #A circuito_abierto
    A_circuito_abierto = tk.Entry(window)
    A_circuito_abierto.pack()
    A_circuito_abierto.place(x=1026, y=420)    

    #P cortocircuito
    P_circuito_abierto = tk.Entry(window)
    P_circuito_abierto.pack()
    P_circuito_abierto.place(x=1026, y=460)
    
    #Potencia reactiva
    S_aparente = tk.Entry(window)
    S_aparente.pack()
    S_aparente.place(x=129, y=548)   

    #Relacion de transformacion
    r_transformacion = tk.Entry(window)
    r_transformacion.pack()
    r_transformacion.place(x=670, y=548)

    #Boton para leer datos
    boton_leer_datos = tk.Button(window, text="Calcular circuito", command=obtener_texto)
    boton_leer_datos.pack()
    boton_leer_datos.place(x=976, y=546)


    #ejecucion del programa
    ejecutar()


    
    
    
