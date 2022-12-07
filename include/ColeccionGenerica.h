#ifndef COLECCIONGENERICA_H
#define COLECCIONGENERICA_H

#include <string>
#include <iostream>

class ColeccionGenerica
{
    protected:
        std::string titulo;
        std::string nombreAutor;
        std::string apellidoAutor;
    public:
        ColeccionGenerica(std::string titulo, std::string nombreAutor, std::string apellidoAutor);
        virtual ~ColeccionGenerica();
        void SetTitulo(std::string titulo);
        void SetNombreAutor(std::string nombreAutor);
        void SetApellidoAutor(std::string apellidoAutor);
        std::string GetTitulo(void);
        std::string GetNombreAutor(void);
        std::string GetApellidoAutor(void);
};

class ColeccionLibros : public ColeccionGenerica
{
    private:
        std::string resenia; // comentario más destacado de la crítica
    public:
        ColeccionLibros(std::string titulo, std::string nombreAutor, std::string apellidoAutor, std::string resenia)
            :ColeccionGenerica(titulo, nombreAutor, apellidoAutor)
        {
            this->resenia = resenia;
        }
        virtual ~ColeccionLibros()
        {

        }
        void SetResenia(std::string resenia)
        {
            this->resenia = resenia;
        }
        std::string getResenia(void)
        {
            return(this->resenia);
        }
};

class ColeccionPeliculas : public ColeccionLibros
{
    private:
        std::string protagonista;
        int anioEstreno;
        float porCritPositivas; // Porcentaje de críticas positivas del público
    public:
        ColeccionPeliculas(std::string titulo, std::string nombreAutor, std::string apellidoAutor, std::string resenia, std::string protganonista, int anioEstreno, float porCritPositivas)
            :ColeccionLibros(titulo, nombreAutor, apellidoAutor, resenia)
        {
             this->protagonista = protganonista;
             this->anioEstreno = anioEstreno;
             this->porCritPositivas = porCritPositivas;
        }
        virtual ~ColeccionPeliculas()
        {

        }
        void SetProtagonista(std::string protagonista)
        {
            this->protagonista = protagonista;
        }
        std::string getProtagonista(void)
        {
            return(this->protagonista);
        }
        void SetAnioEstreno(int anioEstreno)
        {
            this->anioEstreno = anioEstreno;
        }
        int GetAnioEstreno(void)
        {
            return(this->anioEstreno);
        }
        void SetPorCritPositivas(float porCritPositivas)
        {
            this->porCritPositivas = porCritPositivas;
        }
        float getPorCritPositivas(void)
        {
            return(this->porCritPositivas);
        }
};

class ColeccionCanciones : public ColeccionLibros
{
    private:
        std::string interprete;
        int cantReproducciones; // Cantidad de reproducciones en Spotify
    public:
        ColeccionCanciones(std::string titulo, std::string nombreAutor, std::string apellidoAutor, std::string resenia, int cantReproducciones)
            :ColeccionLibros(titulo, nombreAutor, apellidoAutor, resenia)
        {
             this->cantReproducciones = cantReproducciones;
        }
        virtual ~ColeccionCanciones()
        {

        }
        void SetCantReproducciones(int cantReproducciones)
        {
            this->cantReproducciones = cantReproducciones;
        }
        int GetCantReproducciones(void)
        {
            return(this->cantReproducciones);
        }
        void SetInterprete(std::string interprete)
        {
            this->interprete = interprete;
        }
        std::string getInterprete(void)
        {
            return(this->interprete);
        }
};

#endif // COLECCIONGENERICA_H
