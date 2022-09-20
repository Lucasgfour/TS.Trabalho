#include <iostream>

class Pessoa {

protected:
    Pessoa(const std::string nome) : Nome(nome) { }

    static Pessoa* pessoa_;

    std::string Nome;

public:
    Pessoa(Pessoa& other) = delete;

    void operator=(const Pessoa&) = delete;

    static Pessoa* GetInstance(const std::string& nome);

    void setNome(std::string nome) { Nome = nome; }

    void imprimir() { std::cout << "Nome: " << Nome << "\n"; }
};

Pessoa* Pessoa::pessoa_ = nullptr;;

Pessoa* Pessoa::GetInstance(const std::string& nome) {

    if (pessoa_ == nullptr) { pessoa_ = new Pessoa(nome); }
    return pessoa_;
}


int main() {
    Pessoa* pessoa1 = Pessoa::GetInstance("Lucas");
    pessoa1->imprimir();

    Pessoa* pessoa2 = Pessoa::GetInstance("");
    pessoa2->imprimir();

    pessoa2->setNome("Raphael");

    pessoa1->imprimir();
}