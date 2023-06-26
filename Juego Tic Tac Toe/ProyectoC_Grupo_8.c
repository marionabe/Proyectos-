/*
Proyecto de programacion para el curso Programacion Bajo Plataformas Abiertas
de la Universidad de Costa Rica en lenguaje de programacion C destinado a la
recreacion del videojuego Tic Tac Toe (Juego de Gato). Para la creación de este
código fue utilizada la distribución de Ubuntu 18.04/20.04.

Autores: Johan Solis Soto  C07686
         Sergio Camacho B91476
	       Mario Navarro Bejarano B75398
*/

#include <stdio.h>
#include <gtk/gtk.h>


//Variable que controla la jugabilidad  por turnos.
int turno = 0;

/*
Array que contiene la informacion acerca del contenido de cada indice, ya
sea 1 (jugador 1), 2 (jugador 2) o 0 en caso en caso de que aun no se haya
ingresado un valor.
*/
char posiciones_cuadricula[9];

/*
Variable necesaria para ejecutar el reset (se escribe en 1 cuando se solicita
reset)
*/
int reset = 0;

//Variable fija necesaria para ejecutar el loop main de gtk.
int loop = 1;

/*
Variable que indica quien es el ganador
 =2 -> ganó O
 =1 -> ganó X
 =0 -> nadie ha ganado
*/
int ganador = 0;

/*
Variable utilizada para saber cuando alguien ganó, y se usa para bloquear el
los botones del juego en caso de que se desee ingresar algun elemento despues
de terminado el juego.
*/
int bloqueo=0;


void winner(){
    /*
    Función encargada de revisar los indices del array posiciones_cuadricula
    para defenir en base a estas si existe un ganador e indicar quien es el
    ganador. La funcion compara el contenido de los indices de manera que
    formen filas, columnas o diagonales.
    */
    if (
        posiciones_cuadricula[0]==posiciones_cuadricula[1] &&
        posiciones_cuadricula[1]==posiciones_cuadricula[2] &&
        posiciones_cuadricula[2]!=0
        ){
          ganador = posiciones_cuadricula[2];
          bloqueo=1;
    }
    else if(
        posiciones_cuadricula[3] == posiciones_cuadricula[4] &&
        posiciones_cuadricula[4] == posiciones_cuadricula[5] &&
        posiciones_cuadricula[5] != 0
        ){
          ganador = posiciones_cuadricula[5];
          bloqueo =1;
    }
    else if(
        posiciones_cuadricula[6] == posiciones_cuadricula[7] &&
        posiciones_cuadricula[7] == posiciones_cuadricula[8] &&
        posiciones_cuadricula[8] !=0
        ){
          ganador = posiciones_cuadricula[8];
          bloqueo=1;
    }
    else if(
        posiciones_cuadricula[0] == posiciones_cuadricula[3] &&
        posiciones_cuadricula[3] == posiciones_cuadricula[6] &&
        posiciones_cuadricula[6] !=0
        ){
          ganador = posiciones_cuadricula[6];
          bloqueo=1;
    }
    else if(
        posiciones_cuadricula[1] == posiciones_cuadricula[4] &&
        posiciones_cuadricula[4] == posiciones_cuadricula[7] &&
        posiciones_cuadricula[7] != 0
        ){
          ganador = posiciones_cuadricula[7];
          bloqueo=1;
    }
    else if(
        posiciones_cuadricula[2] == posiciones_cuadricula[5] &&
        posiciones_cuadricula[5] == posiciones_cuadricula[8] &&
        posiciones_cuadricula[8] != 0
        ){
          ganador = posiciones_cuadricula[8];
          bloqueo=1;

    }
    else if(
        posiciones_cuadricula[0] == posiciones_cuadricula[4] &&
        posiciones_cuadricula[4] == posiciones_cuadricula[8] &&
        posiciones_cuadricula[8] != 0
        ){
          ganador = posiciones_cuadricula[8];
          bloqueo=1;
    }
    else if(
        posiciones_cuadricula[2] == posiciones_cuadricula[4] &&
        posiciones_cuadricula[4] == posiciones_cuadricula[6] &&
        posiciones_cuadricula[6] != 0
        ){
          ganador = posiciones_cuadricula[6];
          bloqueo=1;
    }
  }


void on_clicked_1_1(GtkWidget *widget, GtkButton *button, gpointer data){
    /*
    Funcion encargada de dibujar un elemento (X u O) a traves de una imagen
    una vez que el boton sea clickeado. Segun el elemento dibujado se ingresa
    un valor en el array posiciones_cuadricula. Este mismo proceso se ejecuta
    en las funciones contiguas designadas a cada uno de los botones de la
    interfaz grafica.
    */
    GtkButton *button_1x1 = (GtkButton*) data;
    if (turno%2 == 0 && posiciones_cuadricula[0] == 0 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/X (1).png");
      posiciones_cuadricula[0] = 1;
      gtk_button_set_image(button_1x1, image);
      turno = turno + 1;
      /*
      Ejecucion de la funcion winner para determinar si hay un ganador una vez
      clickeado este boton.
      */
      winner();
    }

    else if(turno%2 != 0 && posiciones_cuadricula[0] != 1 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/O (1).png");
      gtk_button_set_image(button_1x1, image);
      posiciones_cuadricula[0] = 2;
      turno = turno + 1;
      /*
      Ejecucion de la funcion winner para determinar si hay un ganador una vez
      clickeado este boton.
      */
      winner();
    }
}

void on_clicked_1_2(GtkWidget *widget, GtkButton *button, gpointer data){
    GtkButton *button_1x2 = (GtkButton*) data;
    if (turno%2 == 0 && posiciones_cuadricula[1] == 0 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/X (1).png");
      posiciones_cuadricula[1] = 1;
      gtk_button_set_image(button_1x2, image);
      turno = turno + 1;
      winner();
    }
    else if(turno%2 != 0 && posiciones_cuadricula[1] != 1 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/O (1).png");
      posiciones_cuadricula[1] = 2;
      gtk_button_set_image(button_1x2, image);
      turno = turno + 1;
      winner();
    }
}

void on_clicked_1_3(GtkWidget *widget, GtkButton *button, gpointer data){
    GtkButton *button_1x3 = (GtkButton*) data;
    if (turno%2 == 0 && posiciones_cuadricula[2] == 0 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/X (1).png");
      posiciones_cuadricula[2] = 1;
      gtk_button_set_image(button_1x3, image);
      turno = turno + 1;
      winner();
    }
    else if(turno%2 != 0 && posiciones_cuadricula[2] != 1 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/O (1).png");
      posiciones_cuadricula[2] = 2;
      gtk_button_set_image(button_1x3, image);
      turno = turno + 1;
      winner();
    }
}

void on_clicked_2_1(GtkWidget *widget, GtkButton *button, gpointer data){
    GtkButton *button_2x1 = (GtkButton*) data;
    if (turno%2 == 0 && posiciones_cuadricula[3] == 0 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/X (1).png");
      posiciones_cuadricula[3] = 1;
      gtk_button_set_image(button_2x1, image);
      turno = turno + 1;
      winner();
    }
    else if(turno%2 != 0 && posiciones_cuadricula[3] != 1 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/O (1).png");
      posiciones_cuadricula[3] = 2;
      gtk_button_set_image(button_2x1, image);
      turno = turno + 1;
      winner();
    }
}

void on_clicked_2_2(GtkWidget *widget, GtkButton *button, gpointer data){
    GtkButton *button_2x2 = (GtkButton*) data;
    if (turno%2 == 0 && posiciones_cuadricula[4] == 0 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/X (1).png");
      posiciones_cuadricula[4] = 1;
      gtk_button_set_image(button_2x2, image);
      turno = turno + 1;
      winner();
    }
    else if(turno%2 != 0 && posiciones_cuadricula[4] != 1 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/O (1).png");
      posiciones_cuadricula[4] = 2;
      gtk_button_set_image(button_2x2, image);
      turno = turno + 1;
      winner();
    }
}

void on_clicked_2_3(GtkWidget *widget, GtkButton *button, gpointer data){
    GtkButton *button_2x3 = (GtkButton*) data;
    if (turno%2 == 0 && posiciones_cuadricula[5] == 0 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/X (1).png");
      posiciones_cuadricula[5] = 1;
      gtk_button_set_image(button_2x3, image);
      turno = turno + 1;
      winner();
    }
    else if(turno%2 != 0 && posiciones_cuadricula[5] != 1 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/O (1).png");
      posiciones_cuadricula[5] = 2;
      gtk_button_set_image(button_2x3, image);
      turno = turno + 1;
      winner();
    }
}

void on_clicked_3_1(GtkWidget *widget, GtkButton *button, gpointer data){
    GtkButton *button_3x1 = (GtkButton*) data;
    if (turno%2 == 0 && posiciones_cuadricula[6] == 0 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/X (1).png");
      posiciones_cuadricula[6] = 1;
      gtk_button_set_image(button_3x1, image);
      turno = turno + 1;
      winner();
    }
    else if(turno%2 != 0 && posiciones_cuadricula[6] != 1 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/O (1).png");
      posiciones_cuadricula[6] = 2;
      gtk_button_set_image(button_3x1, image);
      turno = turno + 1;
      winner();
    }
}

void on_clicked_3_2(GtkWidget *widget, GtkButton *button, gpointer data){
    GtkButton *button_3x2 = (GtkButton*) data;
    if (turno%2 == 0 && posiciones_cuadricula[7] == 0 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/X (1).png");
      posiciones_cuadricula[7] = 1;
      gtk_button_set_image(button_3x2, image);
      turno = turno + 1;
      winner();
    }
    else if(turno%2 != 0 && posiciones_cuadricula[7] != 1 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/O (1).png");
      posiciones_cuadricula[7] = 2;
      gtk_button_set_image(button_3x2, image);
      turno = turno + 1;
      winner();
    }
}

void on_clicked_3_3(GtkWidget *widget, GtkButton *button, gpointer data){
    GtkButton *button_3x3 = (GtkButton*) data;
    if (turno%2 == 0 && posiciones_cuadricula[8] == 0 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/X (1).png");
      posiciones_cuadricula[8] = 1;
      gtk_button_set_image(button_3x3, image);
      turno = turno + 1;
      winner();
    }
    else if(turno%2 != 0 && posiciones_cuadricula[8] != 1 && bloqueo==0){
      GtkWidget *image = gtk_image_new_from_file("PNGFiles/O (1).png");
      posiciones_cuadricula[8] = 2;
      gtk_button_set_image(button_3x3, image);
      turno = turno + 1;
      winner();
    }
}


void on_clicked_reset(GtkWidget *widget, gpointer data){
  /*
  Función que hace la solicitud de reset (reset=1) cuando se presiona el boton
  "reiniciar"
  */
  ganador = 0;
  reset = 1;
  bloqueo = 0;
  }


int main(int argc, char* argv[]){
    GtkBuilder *builder;
    GtkWidget *window;
    GtkButton *button_1x1;
    GtkButton *button_1x2;
    GtkButton *button_1x3;
    GtkButton *button_2x1;
    GtkButton *button_2x2;
    GtkButton *button_2x3;
    GtkButton *button_3x1;
    GtkButton *button_3x2;
    GtkButton *button_3x3;
    GtkWidget *quit_button;
    GtkWidget *reset_button;
    GtkWidget *label_1;
    GtkButton *boton_ganador;

    gtk_init(&argc, &argv);

    // Se obtiene el archivo GUI desde la ruta del archivo.
    builder = gtk_builder_new_from_file("Interfaz.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "Ventana Principal"));
    g_signal_connect(window, "destroy", G_CALLBACK(exit), NULL);

    button_1x1 = GTK_BUTTON(
        gtk_builder_get_object(builder, "Boton_1_1")
        );
    button_1x2 = GTK_BUTTON(
        gtk_builder_get_object(builder, "Boton_1_2")
        );
    button_1x3 = GTK_BUTTON(
        gtk_builder_get_object(builder, "Boton_1_3")
        );
    button_2x1 = GTK_BUTTON(
        gtk_builder_get_object(builder, "Boton_2_1")
        );
    button_2x2 = GTK_BUTTON(
        gtk_builder_get_object(builder, "Boton_2_2")
        );
    button_2x3 = GTK_BUTTON(
        gtk_builder_get_object(builder, "Boton_2_3")
        );
    button_3x1 = GTK_BUTTON(
        gtk_builder_get_object(builder, "Boton_3_1")
        );
    button_3x2 = GTK_BUTTON(
        gtk_builder_get_object(builder, "Boton_3_2")
        );
    button_3x3 = GTK_BUTTON(
        gtk_builder_get_object(builder, "Boton_3_3")
        );
    quit_button = GTK_WIDGET(
        gtk_builder_get_object(builder, "Quit_Button")
        );
    reset_button = GTK_WIDGET(
        gtk_builder_get_object(builder, "Reset_Button")
        );
    label_1 = GTK_WIDGET(
        gtk_builder_get_object(builder, "label_1")
        );
    boton_ganador = GTK_BUTTON(
        gtk_builder_get_object(builder, "boton_ganador")
        );


    g_signal_connect(
        button_1x1, "clicked", G_CALLBACK(on_clicked_1_1), label_1
        );
    g_signal_connect(
        button_1x2, "clicked", G_CALLBACK(on_clicked_1_2), label_1
        );
    g_signal_connect(
        button_1x3, "clicked", G_CALLBACK(on_clicked_1_3), label_1
        );
    g_signal_connect(
        button_2x1, "clicked", G_CALLBACK(on_clicked_2_1), label_1
        );
    g_signal_connect(
        button_2x2, "clicked", G_CALLBACK(on_clicked_2_2), label_1
        );
    g_signal_connect(
        button_2x3, "clicked", G_CALLBACK(on_clicked_2_3), label_1
        );
    g_signal_connect(
        button_3x1, "clicked", G_CALLBACK(on_clicked_3_1), label_1
        );
    g_signal_connect(
        button_3x2, "clicked", G_CALLBACK(on_clicked_3_2), label_1
        );
    g_signal_connect(
        button_3x3, "clicked", G_CALLBACK(on_clicked_3_3), label_1
        );
    g_signal_connect(
        quit_button, "clicked", G_CALLBACK(exit), NULL
        );
    g_signal_connect(
        reset_button, "clicked", G_CALLBACK(on_clicked_reset), label_1
        );

    //Bucle de la Ventana
    //Dentro del bucle se revisa si se solicitó un reseteo de las piezas.
    gtk_widget_show_all(window);
    while (loop = 1){
        gtk_main_iteration();
        if (reset == 1){
          /*
          Al momento de ejecutar el reset se le cambia la imagen a los botones
          por la imagen transparente recien cargada.
          */
          GtkWidget *img_trans_1x1 = gtk_image_new_from_file(
              "PNGFiles/imagen_transparente.png"
              );
          gtk_button_set_image(button_1x1, img_trans_1x1);
          GtkWidget *img_trans_1x2 = gtk_image_new_from_file(
              "PNGFiles/imagen_transparente.png"
              );
          gtk_button_set_image(button_1x2, img_trans_1x2);
          GtkWidget *img_trans_1x3 = gtk_image_new_from_file(
              "PNGFiles/imagen_transparente.png"
              );
          gtk_button_set_image(button_1x3, img_trans_1x3);
          GtkWidget *img_trans_2x1 = gtk_image_new_from_file(
              "PNGFiles/imagen_transparente.png"
              );
          gtk_button_set_image(button_2x1, img_trans_2x1);
          GtkWidget *img_trans_2x2 = gtk_image_new_from_file(
              "PNGFiles/imagen_transparente.png"
              );
          gtk_button_set_image(button_2x2, img_trans_2x2);
          GtkWidget *img_trans_2x3 = gtk_image_new_from_file(
              "PNGFiles/imagen_transparente.png"
              );
          gtk_button_set_image(button_2x3, img_trans_2x3);
          GtkWidget *img_trans_3x1 = gtk_image_new_from_file(
              "PNGFiles/imagen_transparente.png"
              );
          gtk_button_set_image(button_3x1, img_trans_3x1);
          GtkWidget *img_trans_3x2 = gtk_image_new_from_file(
              "PNGFiles/imagen_transparente.png"
              );
          gtk_button_set_image(button_3x2, img_trans_3x2);
          GtkWidget *img_trans_3x3 = gtk_image_new_from_file(
              "PNGFiles/imagen_transparente.png"
              );
          gtk_button_set_image(button_3x3, img_trans_3x3);

          /*
          Al momento de ejecutar el reset se cambian todos los elementos en
          el array posiciones_cuadricula a 0 para inciar un juego nuevo.
          */

          posiciones_cuadricula[0]=0;
          posiciones_cuadricula[1]=0;
          posiciones_cuadricula[2]=0;
          posiciones_cuadricula[3]=0;
          posiciones_cuadricula[4]=0;
          posiciones_cuadricula[5]=0;
          posiciones_cuadricula[6]=0;
          posiciones_cuadricula[7]=0;
          posiciones_cuadricula[8]=0;
          reset = 0;
        }
        else{
            gtk_main_iteration();
            if(ganador == 2){
                gtk_label_set_text((GtkLabel  *)label_1, "El ganador es: ");
                GtkWidget *img_ganador_O = gtk_image_new_from_file(
                    "PNGFiles/O (1).png"
                    );
                gtk_button_set_image(boton_ganador, img_ganador_O);
            }
            else if(ganador == 1){
                gtk_label_set_text((GtkLabel  *)label_1, "El ganador es: ");
                GtkWidget *img_ganador_X = gtk_image_new_from_file(
                    "PNGFiles/X (1).png"
                    );
                gtk_button_set_image(boton_ganador, img_ganador_X);
            }
            else if(ganador == 0){
                //Se establece el logo del juego:
                gtk_label_set_text((GtkLabel  *)label_1, "Bienvenido a: ");
                GtkWidget *img_logo = gtk_image_new_from_file(
                    "PNGFiles/logo_juego.png"
                    );
                gtk_button_set_image(boton_ganador, img_logo);
            }
            gtk_main_iteration();
        }
    }
    return 0;
}
