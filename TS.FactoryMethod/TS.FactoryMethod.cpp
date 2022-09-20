#include <iostream>

class Produto {
public:
    virtual ~Produto() {}
    virtual std::string GetDescricao() const = 0;
};

class Computador : public Produto {
public:
    std::string GetDescricao() const override { return "PC -> I5 9400F & RTX 2060"; }
};

class Notebook : public Produto {
public:
    std::string GetDescricao() const override { return "NOTEBOOK -> I7 10750H & GTX 1050"; }
};

class Creator {
public:
    virtual ~Creator() {};
    virtual Produto* FactoryMethod() const = 0;

    std::string ProdutoDescricao() const {
        Produto* Produto = this->FactoryMethod();
        std::string result = "Criador: O produto é " + Produto->GetDescricao();
        delete Produto;
        return result;
    }
};

class ComputadorCreator : public Creator {

public:
    Produto* FactoryMethod() const override { return new Computador(); }
};

class NotebookCreator : public Creator {
public:
    Produto* FactoryMethod() const override { return new Notebook(); }
};

int main() {
    Creator* pc = new ComputadorCreator();
    Creator* note = new NotebookCreator();
    
    std::cout << pc->ProdutoDescricao() << "\n";
    std::cout << note->ProdutoDescricao() << "\n";

    return 0;
}
