#include "Estoque.hpp"

using namespace std;
string k4, m4, n4, o4, q4;
float l4;
bool Estoque::adicionaDisjuntor(DisjuntoreDifResDDR p6){
    if(disjuntoreDifResDDREmEstoque.empty()){
        disjuntoreDifResDDREmEstoque.push_back(p6);
        return true;
    }
    else{
        for(int i = 0; i < disjuntoreDifResDDREmEstoque.size(); i++){
            if(disjuntoreDifResDDREmEstoque[i].getPrecoDoProduto() == p6.getPrecoDoProduto()){
                return false;
            }
        }
        disjuntoreDifResDDREmEstoque.push_back(p6);
        return true;
    }
}
bool Estoque::venderDisjuntor(string pesquisa){
    if(disjuntoreDifResDDREmEstoque.empty()){
        return false;
    }
    else{

        DisjuntoreDifResDDR aux; 
        cout<<"\n\n";
        for(int i = 0; i < disjuntoreDifResDDREmEstoque.size(); i++){
            if(disjuntoreDifResDDREmEstoque[i].getNomeDoProduto() == pesquisa){
                aux = disjuntoreDifResDDREmEstoque[i];
                disjuntoreDifResDDRVendidos.insert(disjuntoreDifResDDRVendidos.begin(), aux);
                disjuntoreDifResDDREmEstoque.erase(disjuntoreDifResDDREmEstoque.begin()+i);
                return true;
            }
        }
        return false;
    }
}
bool Estoque::removerDisjuntorDoEstoque(string pesquisa){
    if(disjuntoreDifResDDREmEstoque.empty()){
        return false;
    }
    else{
        for(int i = 0; i < disjuntoreDifResDDREmEstoque.size(); i++){
            if(disjuntoreDifResDDREmEstoque[i].getNomeDoProduto() == pesquisa){
                disjuntoreDifResDDREmEstoque.erase(disjuntoreDifResDDREmEstoque.begin()+i);
                return true;
            }
        }
        return false;
    }
}
void Estoque::exibiDisjuntorDisponiveis(){
    if(disjuntoreDifResDDREmEstoque.empty()){
        cout<<"\n- Estoque vazio\n";
    }
    else{
		cout<<"\n";
        for(int i = 0; i < disjuntoreDifResDDREmEstoque.size(); i++){
            cout<<"Marca do produto: "<<disjuntoreDifResDDREmEstoque[i].getNomeDoProduto()<<endl;
			cout<<"O preço do produto:"<<disjuntoreDifResDDREmEstoque[i].getPrecoDoProduto()<<endl;
			cout<<"Código de barras: "<<disjuntoreDifResDDREmEstoque[i].getCodigoBarras()<<endl;
			cout<<"Tensão suportada (volts): "<<disjuntoreDifResDDREmEstoque[i].getTensaoSuportada()<<endl;
			cout<<"Ampéres:"<<disjuntoreDifResDDREmEstoque[i].getAmperesSuportado();
			cout<<"Do tipo IDR sim (s) ou não(n):"<<disjuntoreDifResDDREmEstoque[i].getIdrTrueFalse();
			cout<< "\n" <<endl;
        }
    }

}
void Estoque::exibiNomesDisjuntores(string pesquisa){
    if(disjuntoreDifResDDREmEstoque.empty()){
        cout<<"\n- não existe!\n";
    }
    else{
        bool a = false;
        cout<<"\n";
        for(int i = 0; i < disjuntoreDifResDDREmEstoque.size(); i++){
            if(disjuntoreDifResDDREmEstoque[i].getNomeDoProduto() == pesquisa){
                cout<<"Marca do produto: " <<disjuntoreDifResDDREmEstoque[i].getNomeDoProduto()<<endl;
				cout<<"O preço do produto:"<<disjuntoreDifResDDREmEstoque[i].getPrecoDoProduto()<<endl;
				cout<<"Código de barras: "<<disjuntoreDifResDDREmEstoque[i].getCodigoBarras()<<endl;
				cout<<"Tensão suportada (volts): "<<disjuntoreDifResDDREmEstoque[i].getTensaoSuportada()<<endl;
				cout<<"Ampéres:"<<disjuntoreDifResDDREmEstoque[i].getAmperesSuportado();
				cout<<"Do tipo IDR sim (s) ou não(n):"<<disjuntoreDifResDDREmEstoque[i].getIdrTrueFalse();
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


void Estoque::exibiDisjuntorVendidos() {
    if(disjuntoreDifResDDRVendidos.empty()) {
        cout << "\n- Não há disjuntores vendidos\n";
    } else {
        double totalVendas = 0.0;
        cout << "\n";
        for(int i = 0; i < disjuntoreDifResDDRVendidos.size(); i++) {
            cout << "- Produto vendido: " << endl;
            cout << "Marca do produto: " << disjuntoreDifResDDRVendidos[i].getNomeDoProduto() << endl;
            cout << "O preço do produto: " << disjuntoreDifResDDRVendidos[i].getPrecoDoProduto() << endl;
            totalVendas += disjuntoreDifResDDRVendidos[i].getPrecoDoProduto();
            cout << "\n" << endl;
        }
        double mediaVendas = totalVendas / disjuntoreDifResDDRVendidos.size();
        cout.precision(2);
        cout << "Soma do dinheiro total em vendas: R$" << totalVendas << endl;
        cout << "Quantidade de vendas realizadas: " << disjuntoreDifResDDRVendidos.size() << endl;
        cout << "Média de vendas por produto: R$" << ceil(mediaVendas * 100) / 100 << endl;
    }
}
void Estoque::salvarNoArquivoDisjuntoreDifResDDR(string reguser){
	string nomePasta = "arquivos/" + reguser + "DisjuntoresEstoque.txt";
	ofstream arquivo(nomePasta.c_str(), ios::app);
    if (arquivo.is_open()) {
	    for(int i = 0; i < disjuntoreDifResDDREmEstoque.size(); i++){
	        k4 = disjuntoreDifResDDREmEstoque[i].getNomeDoProduto();
			l4 = disjuntoreDifResDDREmEstoque[i].getPrecoDoProduto();
			m4 = disjuntoreDifResDDREmEstoque[i].getCodigoBarras();
			n4 = disjuntoreDifResDDREmEstoque[i].getTensaoSuportada();
			o4 = disjuntoreDifResDDREmEstoque[i].getAmperesSuportado();
			q4 = disjuntoreDifResDDREmEstoque[i].getIdrTrueFalse();
			arquivo<<k4<<' '<<l4<<' '<<m4<<' '<<n4<< ' '<<o4 <<' '<<q4<< '\n';
	    }
	    arquivo.close();
	} else {
        cout << "Erro ao abrir o arquivo!" << endl;
    } 
}
void Estoque::salvarNoArquivoDisjuntoreDifResDDRVendidos(string reguser){
	string nomePasta = "arquivos/" + reguser + "DisjuntoresVendidos.txt";
	ofstream arquivo(nomePasta.c_str(), ios::app);
    if (arquivo.is_open()) {
	    for(int i = 0; i < disjuntoreDifResDDRVendidos.size(); i++){
			k4 = disjuntoreDifResDDRVendidos[i].getNomeDoProduto();
			l4 = disjuntoreDifResDDRVendidos[i].getPrecoDoProduto();
			arquivo<<k4<<' '<<l4<< '\n';
	    }
	    arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo!" << endl;
    }
}

bool Estoque::adicionaDisjuntoreDifResDDRVendidos(DisjuntoreDifResDDR p6){
    if(disjuntoreDifResDDRVendidos.empty()){
        disjuntoreDifResDDRVendidos.push_back(p6);
        return true;
    }
    else{
        for(int i = 0; i < disjuntoreDifResDDRVendidos.size(); i++){
            if(disjuntoreDifResDDRVendidos[i].getPrecoDoProduto() == p6.getPrecoDoProduto()){
                return false;
            }
        }
        disjuntoreDifResDDRVendidos.push_back(p6);
        return true;
    }
}
void Estoque::apagarVetorDisjuntores(){
    disjuntoreDifResDDREmEstoque.clear();
}

void Estoque::apagarVetorDisjuntoresVendidos() {
    disjuntoreDifResDDRVendidos.clear();
}