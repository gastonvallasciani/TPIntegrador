#include "ColeccionGenerica.h"

ColeccionGenerica::ColeccionGenerica(std::string titulo, std::string nombreAutor, std::string apellidoAutor)
{
    this->titulo = titulo;
    this->nombreAutor = nombreAutor;
    this->apellidoAutor = apellidoAutor;
}

ColeccionGenerica::~ColeccionGenerica()
{
    //std::cout << "Se ejecuta el destructor" << std::endl;
}

void ColeccionGenerica::SetTitulo(std::string titulo)
{
    this->titulo = titulo;
}
void ColeccionGenerica::SetNombreAutor(std::string nombreAutor)
{
    this->nombreAutor = nombreAutor;
}
void ColeccionGenerica::SetApellidoAutor(std::string apellidoAutor)
{
    this->apellidoAutor = apellidoAutor;
}
std::string ColeccionGenerica::GetTitulo(void)
{
    return(this->titulo);
}
std::string ColeccionGenerica::GetNombreAutor(void)
{
    return(this->nombreAutor);
}
std::string ColeccionGenerica::GetApellidoAutor(void)
{
    return(this->apellidoAutor);
}
