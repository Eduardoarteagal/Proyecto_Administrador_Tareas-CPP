#include <iostream>
#include <vector>
#include <string>

class Tarea {
private:
    int id;
    std::string titulo;
    std::string descripcion;
    std::string fechaLimite;

public:
    Tarea(int id, const std::string& titulo, const std::string& descripcion, const std::string& fechaLimite)
        : id(id), titulo(titulo), descripcion(descripcion), fechaLimite(fechaLimite) {}

    // Métodos para obtener y modificar los atributos de la tarea
    int getId() const { return id; }
    std::string getTitulo() const { return titulo; }
    std::string getDescripcion() const { return descripcion; }
    std::string getFechaLimite() const { return fechaLimite; }

    void setTitulo(const std::string& nuevoTitulo) { titulo = nuevoTitulo; }
    void setDescripcion(const std::string& nuevaDescripcion) { descripcion = nuevaDescripcion; }
    void setFechaLimite(const std::string& nuevaFechaLimite) { fechaLimite = nuevaFechaLimite; }

    void mostrarTarea() const {
        std::cout << "ID: " << id << "\n"
                  << "Titulo: " << titulo << "\n"
                  << "Descripcion: " << descripcion << "\n"
                  << "Fecha Limite: " << fechaLimite << "\n";
    }
};

class AdministradorDeTareas {
private:
    std::vector<Tarea> listaDeTareas;
    int idActual;

public:
    AdministradorDeTareas() : idActual(1) {}

    // Añadir una tarea
    void agregarTarea(const std::string& titulo, const std::string& descripcion, const std::string& fechaLimite) {
        listaDeTareas.emplace_back(idActual, titulo, descripcion, fechaLimite);
        idActual++;
        std::cout << "Tarea anadida con exito.\n";
    }

    // Editar una tarea
    void editarTarea(int id) {
        for (auto& tarea : listaDeTareas) {
            if (tarea.getId() == id) {
                std::string nuevoTitulo, nuevaDescripcion, nuevaFechaLimite;
                std::cout << "Ingrese el nuevo titulo: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoTitulo);
                std::cout << "Ingrese la nueva descripcion: ";
                std::getline(std::cin, nuevaDescripcion);
                std::cout << "Ingrese la nueva fecha limite: ";
                std::getline(std::cin, nuevaFechaLimite);

                tarea.setTitulo(nuevoTitulo);
                tarea.setDescripcion(nuevaDescripcion);
                tarea.setFechaLimite(nuevaFechaLimite);
                std::cout << "Tarea editada con exito.\n";
                return;
            }
        }
        std::cout << "Tarea con ID " << id << " no encontrada.\n";
    }

    // Eliminar una tarea
    void eliminarTarea(int id) {
        for (auto it = listaDeTareas.begin(); it != listaDeTareas.end(); ++it) {
            if (it->getId() == id) {
                listaDeTareas.erase(it);
                std::cout << "Tarea eliminada con exito.\n";
                return;
            }
        }
        std::cout << "Tarea con ID " << id << " no encontrada.\n";
    }

    // Mostrar todas las tareas
    void mostrarTareas() const {
        if (listaDeTareas.empty()) {
            std::cout << "No hay tareas en la lista.\n";
        } else {
            for (const auto& tarea : listaDeTareas) {
                tarea.mostrarTarea();
                std::cout << "------------------------\n";
            }
        }
    }
};

int main() {
    AdministradorDeTareas admin;
    int opcion;

    do {
        std::cout << "\n--- Administrador de Tareas Personales ---\n";
        std::cout << "1. Anadir Tarea\n";
        std::cout << "2. Editar Tarea\n";
        std::cout << "3. Eliminar Tarea\n";
        std::cout << "4. Mostrar Tareas\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string titulo, descripcion, fechaLimite;
                std::cin.ignore();  // Limpiar el buffer del newline
                std::cout << "Titulo de la tarea: ";
                std::getline(std::cin, titulo);
                std::cout << "Descripcion de la tarea: ";
                std::getline(std::cin, descripcion);
                std::cout << "Fecha limite (DD/MM/AAAA): ";
                std::getline(std::cin, fechaLimite);
                admin.agregarTarea(titulo, descripcion, fechaLimite);
                break;
            }
            case 2: {
                int id;
                std::cout << "Ingrese el ID de la tarea a editar: ";
                std::cin >> id;
                admin.editarTarea(id);
                break;
            }
            case 3: {
                int id;
                std::cout << "Ingrese el ID de la tarea a eliminar: ";
                std::cin >> id;
                admin.eliminarTarea(id);
                break;
            }
            case 4:
                admin.mostrarTareas();
                break;
        }
    } while (opcion != 0);

    return 0;
}
