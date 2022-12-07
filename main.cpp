#include <iostream>
#include <vector>

#include "ColeccionGenerica.h"

void menu_ingreso_libro(ColeccionLibros& libro, std::vector<ColeccionLibros>& lista_libros);
void menu_ingreso_pelicula(ColeccionPeliculas& pelicula, std::vector<ColeccionPeliculas>& lista_peliculas);
void menu_ingreso_cancion(ColeccionCanciones& cancion, std::vector<ColeccionCanciones>& lista_canciones);

typedef enum{
    STARTUP = 0,
    MENU = 1,
    MENU_INGRESO_LIBRO = 2,
    MENU_INGRESO_CANCION = 3,
    MENU_INGRESO_PELICULA = 4,
    MENU_VISUALIZAR_COLECCION_LIBROS = 5,
    MENU_VISUALIZAR_COLECCION_PELICULAS = 6,
    MENU_VISUALIZAR_COLECCION_CANCIONES = 7,
    FIN_DE_PROGRAMA = 8,
}app_states;

typedef struct{
    app_states actual_state;
    int accion_elegida;
    bool flag_fin;
}app_t;

int main()
{
    app_t app;
    std::size_t index;
    std::string str_aux;
    int anio_aux, cant_reproducciones_aux;
    bool mostrar_info = false;

    std::vector<ColeccionLibros> lista_libros;
    std::vector<ColeccionPeliculas> lista_peliculas;
    std::vector<ColeccionCanciones> lista_canciones;

    ColeccionLibros libro = ColeccionLibros("generico" , "nombre", "apellido", "muy bueno");
    ColeccionPeliculas pelicula = ColeccionPeliculas("generico" , "nombre", "apellido", "muy bueno", "protagonista", 2000, 85);
    ColeccionCanciones cancion = ColeccionCanciones("generico" , "nombre", "apellido", "muy bueno", 2000);

    app.actual_state = STARTUP;

    app.flag_fin = false;

    while(1)
    {
        switch(app.actual_state)
        {
        case STARTUP:
            std::cout << "Bienvenido !!!" << std::endl;
            app.actual_state = MENU;
            break;
        case MENU:
            std::cout << "Seleccione el numero de accion que desea llevar a cabo:" << std::endl;
            std::cout << "1: Ingresar nuevo libro" << std::endl;
            std::cout << "2: Ingresar nueva pelicula" << std::endl;
            std::cout << "3: Ingresar nueva cancion" << std::endl;
            std::cout << "4: Visualizar coleccion de libros" << std::endl;
            std::cout << "5: Visualizar coleccion de peliculas" << std::endl;
            std::cout << "6: Visualizar coleccion de canciones" << std::endl;
            std::cout << "7: Finalizar programa" << std::endl;
            std::cin >> app.accion_elegida;
            switch(app.accion_elegida)
            {
            case 1:
                app.actual_state = MENU_INGRESO_LIBRO;
                break;
            case 2:
                app.actual_state = MENU_INGRESO_PELICULA;
                break;
            case 3:
                app.actual_state = MENU_INGRESO_CANCION;
                break;
            case 4:
                app.actual_state = MENU_VISUALIZAR_COLECCION_LIBROS;
                break;
            case 5:
                app.actual_state = MENU_VISUALIZAR_COLECCION_PELICULAS;
                break;
            case 6:
                app.actual_state = MENU_VISUALIZAR_COLECCION_CANCIONES;
                break;
            case 7:
                app.actual_state = FIN_DE_PROGRAMA;
                break;
            default:
                std::cout << "Eleccion incorrecta!!!" << std::endl;
                break;
            }
            break;
        case MENU_INGRESO_LIBRO:
            menu_ingreso_libro(libro, lista_libros);
            app.actual_state = MENU;
            break;
        case MENU_INGRESO_CANCION:
            menu_ingreso_cancion(cancion, lista_canciones);
            app.actual_state = MENU;
            break;
        case MENU_INGRESO_PELICULA:
            menu_ingreso_pelicula(pelicula, lista_peliculas);
            app.actual_state = MENU;
            break;
        case MENU_VISUALIZAR_COLECCION_LIBROS:
            for (index = 0; index < lista_libros.size(); index++)
            {
                std::cout << std::endl << "Libro numero: " << index + 1 << std::endl;
                std::cout << "Titulo del libro: " <<lista_libros[index].GetTitulo() << std::endl;
                std::cout << "Autor: " <<lista_libros[index].GetNombreAutor() + " " + lista_libros[index].GetApellidoAutor() << std::endl;
                std::cout << "Resenia: " <<lista_libros[index].getResenia() << std::endl << std::endl;
            }
            app.actual_state = MENU;
            break;
        case MENU_VISUALIZAR_COLECCION_PELICULAS:
            while(1)
            {
                std::cout << "Desea visualizar una coleccion de peliculas por anio? y/n" << std::endl;
                std::cin >> str_aux;
                if(str_aux == "y")
                {
                    std::cout << "Ingrese el anio: " << std::endl;
                    std::cin >> anio_aux;
                    break;
                }
                else if(str_aux == "n")
                {
                     std::cout << "La coleccion de peliculas se visualizara en su totalidad" << std::endl;
                     break;
                }
            }

            for (index = 0; index < lista_peliculas.size(); index++)
            {
                mostrar_info = false;
                if((str_aux == "y") && (anio_aux == lista_peliculas[index].GetAnioEstreno()))
                {
                    mostrar_info = true;
                }
                else if(str_aux == "n")
                {
                    mostrar_info = true;
                }

                if(mostrar_info == true)
                {
                    std::cout << std::endl << "Pelicula numero: " << index + 1 << std::endl;
                    std::cout << "Titulo de la pelicula: " <<lista_peliculas[index].GetTitulo() << std::endl;
                    std::cout << "Autor: " <<lista_peliculas[index].GetNombreAutor() + " " + lista_peliculas[index].GetApellidoAutor() << std::endl;
                    std::cout << "Protagonista: " <<lista_peliculas[index].getProtagonista() << std::endl;
                    std::cout << "Anio de estreno: " <<lista_peliculas[index].GetAnioEstreno() << std::endl;
                    std::cout << "Porcentaje de criticas positivas del publico: " <<lista_peliculas[index].getPorCritPositivas() << "%" << std::endl;
                    std::cout << "Resenia: " <<lista_peliculas[index].getResenia() << std::endl << std::endl;
                }
            }
            app.actual_state = MENU;
            break;
        case MENU_VISUALIZAR_COLECCION_CANCIONES:
            while(1)
            {
                std::cout << "Desea visualizar la coleccion de canciones que supere un numero de reproducciones en Spotify en particular? y/n" << std::endl;
                std::cin >> str_aux;
                if(str_aux == "y")
                {
                    std::cout << "Ingrese la cantidad de reproducciones a superar: " << std::endl;
                    std::cin >> anio_aux;
                    break;
                }
                else if(str_aux == "n")
                {
                     std::cout << "La coleccion de canciones se visualizara en su totalidad" << std::endl;
                     break;
                }
            }

            for (index = 0; index < lista_canciones.size(); index++)
            {
                mostrar_info = false;
                if((str_aux == "y") && (cant_reproducciones_aux < lista_canciones[index].GetCantReproducciones()))
                {
                    mostrar_info = true;
                }
                else if(str_aux == "n")
                {
                    mostrar_info = true;
                }

                if(mostrar_info == true)
                {
                    std::cout << std::endl << "Cancion numero: " << index + 1 << std::endl;
                    std::cout << "Titulo de la cancion: " <<lista_canciones[index].GetTitulo() << std::endl;
                    std::cout << "Autor: " <<lista_canciones[index].GetNombreAutor() + " " + lista_canciones[index].GetApellidoAutor() << std::endl;
                    std::cout << "Interprete: " <<lista_canciones[index].getInterprete() << std::endl;
                    std::cout << "Cantidad de reproducciones en Spotify: " << lista_canciones[index].GetCantReproducciones() << std::endl;
                    std::cout << "Resenia: " <<lista_canciones[index].getResenia() << std::endl << std::endl;
                }
            }
            app.actual_state = MENU;
            break;
        case FIN_DE_PROGRAMA:
            app.flag_fin = true;
            break;
        default:
            break;
        }

        if(app.flag_fin == true)
        {
            break;
        }
    }


    std::cout << "Fin del programa!" << std::endl;
    return 0;
}


void menu_ingreso_libro(ColeccionLibros& libro, std::vector<ColeccionLibros>& lista_libros)
{
    std::string str_aux {};

    std::getline(std::cin, str_aux); // dummy getline
    std::cout << "Ingrese el titulo del libro" << std::endl;
    std::getline(std::cin, str_aux);
    libro.SetTitulo(str_aux);
    std::cout << "Ingrese el nombre del autor del libro" << std::endl;
    std::cin >> str_aux;
    libro.SetNombreAutor(str_aux);
    std::cout << "Ingrese el apellido del autor del libro" << std::endl;
    std::cin >> str_aux;
    libro.SetApellidoAutor(str_aux);
    std::getline(std::cin, str_aux); // dummy getline
    std::cout << "Ingrese la resenia del libro" << std::endl;
    std::getline(std::cin, str_aux);
    libro.SetResenia(str_aux);
    std::cout << "Nuevo libro guardado correctamente" << std::endl;
    lista_libros.push_back(libro);
    //libro_aux = lista_libros.back();
}

void menu_ingreso_pelicula(ColeccionPeliculas& pelicula, std::vector<ColeccionPeliculas>& lista_peliculas)
{
    std::string str_aux {};
    int int_aux = 0;
    float float_aux = 0.0;

    std::getline(std::cin, str_aux); // dummy getline
    std::cout << "Ingrese el titulo de la pelicula" << std::endl;
    std::getline(std::cin, str_aux);
    pelicula.SetTitulo(str_aux);
    std::cout << "Ingrese el nombre del autor de la pelicula" << std::endl;
    std::cin >> str_aux;
    pelicula.SetNombreAutor(str_aux);
    std::cout << "Ingrese el apellido del autor de la pelicula" << std::endl;
    std::cin >> str_aux;
    pelicula.SetApellidoAutor(str_aux);
    std::getline(std::cin, str_aux); // dummy getline
    std::cout << "Ingrese el nombre del protagonista de la pelicula" << std::endl;
    std::getline(std::cin, str_aux);
    pelicula.SetProtagonista(str_aux);
    std::cout << "Ingrese el anio de estreno de la pelicula" << std::endl;
    std::cin >> int_aux;
    pelicula.SetPorCritPositivas(int_aux);
    std::cout << "Ingrese el porcentaje de criticas positivas del publico" << std::endl;
    std::cin >> float_aux;
    pelicula.SetPorCritPositivas(float_aux);
    std::getline(std::cin, str_aux); // dummy getline
    std::cout << "Ingrese la resenia de la pelicula" << std::endl;
    std::getline(std::cin, str_aux);
    pelicula.SetResenia(str_aux);
    std::cout << "Nueva pelicula guardada correctamente" << std::endl;
    lista_peliculas.push_back(pelicula);
}

void menu_ingreso_cancion(ColeccionCanciones& cancion, std::vector<ColeccionCanciones>& lista_canciones)
{
    std::string str_aux {};
    int int_aux = 0;

    std::getline(std::cin, str_aux); // dummy getline
    std::cout << "Ingrese el titulo de la cancion" << std::endl;
    std::getline(std::cin, str_aux);
    cancion.SetTitulo(str_aux);
    std::cout << "Ingrese el nombre del autor de la cancion" << std::endl;
    std::cin >> str_aux;
    cancion.SetNombreAutor(str_aux);
    std::cout << "Ingrese el apellido del autor de la cancion" << std::endl;
    std::cin >> str_aux;
    cancion.SetApellidoAutor(str_aux);
    std::getline(std::cin, str_aux); // dummy getline
    std::cout << "Ingrese el nombre del interprete de la cancion" << std::endl;
    std::getline(std::cin, str_aux);
    cancion.SetInterprete(str_aux);
    std::cout << "Ingrese la cantidad de reproducciones en Spotify" << std::endl;
    std::cin >> int_aux;
    cancion.SetCantReproducciones(int_aux);
    std::getline(std::cin, str_aux); // dummy getline
    std::cout << "Ingrese la resenia de la cancion" << std::endl;
    std::getline(std::cin, str_aux);
    cancion.SetResenia(str_aux);
    std::cout << "Nueva cancion guardada correctamente" << std::endl;
    lista_canciones.push_back(cancion);
}



