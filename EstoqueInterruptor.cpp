#include "Estoque.hpp"

using namespace std;
string k3, m3, n3, o3;
float l3;
bool Estoque::adicionaInterruptores(InterruptoresDR p4){
    if(interruptoresDREmEstoque.empty()){
        interruptoresDREmEstoque.push_back(p4);
        return true;
    }
    else{
        for(int i = 0; i < interruptoresDREmEstoque.size(); i++){
            if(interruptoresDREmEstoque[i].getPrecoDoProduto() == p4.getPrecoDoProduto()){
                return false;
            }
        }
        interruptoresDREmEstoque.push_back(p4);
        return true;
    }
}
bool Estoque::venderInterruptores(string pesquisa){
    if(interruptoresDREmEstoque.empty()){
        return false;
    }
    else{

        InterruptoresDR aux; 
        cout<<"\n\n";
        for(int i = 0; i < interruptoresDREmEstoque.size(); i++){
            if(interruptoresDREmEstoque[i].getNomeDoProduto() == pesquisa){
                aux = interruptoresDREmEstoque[i];
                interruptoresDRVendidos.insert(interruptoresDRVendidos.begin(), aux);
                interruptoresDREmEstoque.erase(interruptoresDREmEstoque.begin()+i);
                return true;
            }
        }
        return false;
    }
}
bool Estoque::removerInterruptoresDoEstoque(string pesquisa){
    if(interruptoresDREmEstoque.empty()){
        return false;
    }
    else{
        for(int i = 0; i < interruptoresDREmEstoque.size(); i++){
            if(interruptoresDREmEstoque[i].getNomeDoProduto() == pesquisa){
                interruptoresDREmEstoque.erase(interruptoresDREmEstoque.begin()+i);
                return true;
            }
        }
        return false;
    }
}
void Estoque::exibiAsInterruptoresDisponiveis(){
    if(interruptoresDREmEstoque.empty()){
        cout<<"\n- Estoque vazio\n";
    }
    else{
		cout<<"\n";
        for(int i = 0; i < interruptoresDREmEstoque.size(); i++){
            cout<<"Marca do produto: "<<interruptoresDREmEstoque[i].getNomeDoProduto()<<endl;
			cout<<"O preço do produto:"<<interruptoresDREmEstoque[i].getPrecoDoProduto()<<endl;
			cout<<"Código de barras: "<<interruptoresDREmEstoque[i].getCodigoBarras()<<endl;
			cout<<"Tensão suportada (volts): "<<interruptoresDREmEstoque[i].getTensaoSuportada()<<endl;
			cout<<"Ampéres:"<<interruptoresDREmEstoque[i].getAmperesSuportado();
			cout<< "\n" <<endl;
        }
    }

}
void Estoque::exibiNomesDosInterruptores(string pesquisa){
    if(interruptoresDREmEstoque.empty()){
        cout<<"\n- não existe!\n";
    }
    else{
        bool a = false;
        cout<<"\n";
        for(int i = 0; i < interruptoresDREmEstoque.size(); i++){
            if(interruptoresDREmEstoque[i].getNomeDoProduto() == pesquisa){
                cout<<"Marca do produto: " <<interruptoresDREmEstoque[i].getNomeDoProduto()<<endl;
				cout<<"O preço do produto:"<<interruptoresDREmEstoque[i].getPrecoDoProduto()<<endl;
				cout<<"Código de barras: "<<interruptoresDREmEstoque[i].getCodigoBarras()<<endl;
				cout<<"Tensão suportada (volts): "<<interruptoresDREmEstoque[i].getTensaoSuportada()<<endl;
				cout<<"Ampéres:"<<interruptoresDREmEstoque[i].getAmperesSuportado();
				cout<< "\n" <<endl;
                a = true;
                break;
            }
        }
        if(a == false){
            cout<<"\n- não existe!\n";
        }
    }
}


void Estoque::exibiInterruptoresVendidos() {
	if(interruptoresDRVendidos.empty()) {
		cout << "\n- Não há interruptores vendidos\n";
	} else {
		double totalVendas = 0.0;
		cout << "\n";
		for(int i = 0; i < interruptoresDRVendidos.size(); i++) {
		cout << "- Produto vendido: " << endl;
		cout << "Marca do produto: " << interruptoresDRVendidos[i].getNomeDoProduto() << endl;
		cout << "O preço do produto: " << interruptoresDRVendidos[i].getPrecoDoProduto() << endl;
		totalVendas += interruptoresDRVendidos[i].getPrecoDoProduto();
		cout << "\n" << endl;
		}
		double mediaVendas = totalVendas / interruptoresDRVendidos.size();
		cout << "Quantidade de vendas: " << interruptoresDRVendidos.size() << endl;
		cout << "Média das vendas: R$" << fixed << setprecision(2) << ceil(mediaVendas*100)/100 << endl;
	}
}

void Estoque::salvarNoArquivoInterruptoresDR(string reguser){
	string nomePasta = "arquivos/" + reguser + "InterruptoresEstoque.txt";
	ofstream arquivo(nomePasta.c_str(), ios::app);
    if (arquivo.is_open()) {
	    for(int i = 0; i < interruptoresDREmEstoque.size(); i++){
	        k3 = interruptoresDREmEstoque[i].getNomeDoProduto();
			l3 = interruptoresDREmEstoque[i].getPrecoDoProduto();
			m3 = interruptoresDREmEstoque[i].getCodigoBarras();
			n3 = interruptoresDREmEstoque[i].getTensaoSuportada();
			o3 = interruptoresDREmEstoque[i].getAmperesSuportado();
			arquivo<<k3<<' '<<l3<<' '<<m3<<' '<<n3<< ' '<<o3<< "\n";
	    }
	    arquivo.close();
	} else {
        cout << "Erro ao abrir o arquivo!" << endl;
    } 	
}
void Estoque::salvarNoArquivoInterruptoresDRVendidos(string reguser){
	string nomePasta = "arquivos/" + reguser + "InterruptoresVendidos.txt";
	ofstream arquivo(nomePasta.c_str(), ios::app);
    if (arquivo.is_open()) {
	    for(int i = 0; i < interruptoresDRVendidos.size(); i++){
	        k3 = interruptoresDRVendidos[i].getNomeDoProduto();
			l3 = interruptoresDRVendidos[i].getPrecoDoProduto();
			arquivo<<k3<<' '<<l3<< "\n";
	    }
	    arquivo.close();
	} else {
        cout << "Erro ao abrir o arquivo!" << endl;
    } 
}
bool Estoque::adicionaInterruptoresDRVendidos(InterruptoresDR p4){
    if(interruptoresDRVendidos.empty()){
        interruptoresDRVendidos.push_back(p4);
        return true;
    }
    else{
        for(int i = 0; i < interruptoresDRVendidos.size(); i++){ 
            if(interruptoresDRVendidos[i].getPrecoDoProduto() == p4.getPrecoDoProduto()){ 
                return false;
            }
        }
        interruptoresDRVendidos.push_back(p4);
        return true;
    }
}

void Estoque::apagarVetorInterruptor() {
    interruptoresDREmEstoque.clear();
}
void Estoque::apagarVetorInterruptorVendido() {
    interruptoresDRVendidos.clear();
}