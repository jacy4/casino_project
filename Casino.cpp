#include "Casino.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>//bib para fazer o numero aleatorio
#include <sstream>//para fazer o separador do fich txt
#include <ctime>//para incluir o time
#include <vector>


Casino::Casino(string nome)
{
	NOME = nome;
	hora_inicio=0;
	hora_fim=0;
	max_jog=0;	
}

Casino::~Casino()
{
	
	
}

bool Casino::Add_USER(User *u) 
{
	LUS.push_back(u);
	return true;
}

bool Casino::Add_MAQUINA(Maquina *m)
{
	LM.push_back(m);
	return true;
	 	
} 

void Casino::Show()
{
	cout << "NOME: " << NOME <<endl;
	for(list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it)
        (*it)->Show();
        
    for(list<User *>::iterator it = LUS.begin(); it != LUS.end(); ++it)
        (*it)->Show();
    cout<<"MAX_JOGADORES:"<<max_jog<<endl;
    cout<<"HORA_INICIO:"<<hora_inicio<<endl;
    cout<<"HORA_FIM:"<<hora_fim<<endl;
    
}

Maquina *Casino::PesquisarMaquina(int id_maq)
{
	for(list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it)
	{
        if ((*it)->GET_ID_MAQUINA() == id_maq)
        {
        	
            //vector<int> posicao = (*it)->GET_POSICAO_MAQUINA();
            //int x = posicao[0]; // Access the first element
    		//int y = posicao[1];
            //cout <<"encontrei a maquina  " << (*it)->GET_NOME_MAQUINA() << " na posicao  (" << x << ", " << y << ")" <<endl;
}
}
    return NULL;
}

void Casino::Desligar(int id_maq) 
{
	Maquina* maquina = PesquisarMaquina(id_maq);
	if(maquina){
		cout <<"maquina found. A desligar..." << endl;
		maquina->Desligar();
	} else{ cout <<"maquina not found "<< endl;}
	
}

void Casino::carregarDadosDeXML(const string& nome_arquivo) 
{
    ifstream arquivo(nome_arquivo);//cria o objeto
    if (!arquivo.is_open()) 
	{
        cout << "Não foi possível abrir o arquivo!" << endl;
        return;
    }
    
    string linha;
    bool entrei_defenicoes = false;
    bool entrei_maquinas=false;
     bool estou_dentro_maquina = false;
	string nome_maq;
    int probg,premio,x,y,temp_Aviso;
    while (getline(arquivo, linha)) 
	{
        // Remove espaços em branco no início e no fim da linha
        linha.erase(0, linha.find_first_not_of(" \n\r\t"));
        linha.erase(linha.find_last_not_of(" \n\r\t") + 1);
        
        
        if (linha == "<DEFINICOES>") 
		{
            entrei_defenicoes = true;
            
        } else if (linha == "</DEFINICOES>") 
		{
            entrei_defenicoes = false;
            
        }else if(linha=="<LISTA_MAQ>")
        {
        	entrei_maquinas=true;
        	
		}else if(linha=="</LISTA_MAQ>")
		{
			entrei_maquinas=false;
			
		}
        
        if(entrei_defenicoes)
        {
        	if (linha.find("<NOME>") != string::npos)//se a linha for valida
			{
            NOME = linha.substr(6,linha.find("</NOME>")-6);//extrai o conteudo que está entre
        	}else if(linha.find("<MAX_JOG>")!=string::npos)
        	{
        		max_jog =stoi( linha.substr(9,linha.find("</MAX_JOG>")-9));//converte para inteiro
			}else if(linha.find("<HORA_INICIO")!=string::npos)
			{
				hora_inicio= stoi(linha.substr(13,linha.find("</HORA_INICIO>")-13));
			}else if(linha.find("<HORA_FIM")!=string::npos)
			{
				hora_fim=stoi(linha.substr(10,linha.find("</HORA_FIM>")-10));
			}
		}
		if (entrei_maquinas) {
            if (linha == "<MAQUINA>") {
                // Reinicia as informações para a nova máquina
                nome_maq.clear();
                probg = premio = x = y = temp_Aviso = 0;
                estou_dentro_maquina = true; // Agora estamos dentro de uma <MAQUINA>
            } else if (linha == "</MAQUINA>") {
                estou_dentro_maquina = false; // Saiu da <MAQUINA>
                // Quando chegar no fim da definição de uma máquina, crie e adicione à lista
                Maquina *novaMaquina = new Maquina(1,nome_maq,premio ,probg ,  temp_Aviso,x, y);
                Add_MAQUINA(novaMaquina);
            } else if (estou_dentro_maquina) { // Verifique se estamos dentro de uma tag <MAQUINA>
                // Extrai informações da máquina aqui...
                if (linha.find("<NOME>") != string::npos) {
                    nome_maq = linha.substr(linha.find("<NOME>") + 6, linha.find("</NOME>") - linha.find("<NOME>") - 6);
                } else if (linha.find("<PROB_G>") != string::npos) {
                    probg = stoi(linha.substr(linha.find("<PROB_G>") + 8, linha.find("</PROB_G>") - linha.find("<PROB_G>") - 8));
                } else if (linha.find("<PREMIO>") != string::npos) {
                    premio = stoi(linha.substr(linha.find("<PREMIO>") + 8, linha.find("</PREMIO>") - linha.find("<PREMIO>") - 8));
                } else if (linha.find("<X>") != string::npos) {
                    x = stoi(linha.substr(linha.find("<X>") + 3, linha.find("</X>") - linha.find("<X>") - 3));
                } else if (linha.find("<Y>") != string::npos) {
                    y = stoi(linha.substr(linha.find("<Y>") + 3, linha.find("</Y>") - linha.find("<Y>") - 3));
                } else if (linha.find("<TEMP_AVISO>") != string::npos) {
                    temp_Aviso = stoi(linha.substr(linha.find("<TEMP_AVISO>") + 12, linha.find("</TEMP_AVISO>") - linha.find("<TEMP_AVISO>") - 12));
                }
               
            }
        }
    }
		cout<<"oiiiiisisisi"<<endl;
	arquivo.close();	
        
}
 
void Casino::pessoas_entrando_aleatorio()
{
	ifstream arquivo("pessoas.txt");//cria o objeto
    if (!arquivo.is_open()) 
	{
        cout << "Não foi possível abrir o arquivo!" << endl;
        return;
    }
    
    //--------gerar o numero de pessoas que queremos importar
   srand(static_cast<unsigned int>(time(nullptr)));//gera a semente de numeros para nao serem os mesmos
   int numero_aleatorio=rand()%10+5;//gera um numero entre 5 a 10;
   while(numero_aleatorio>10)//verificação para nao ultrapassar o escopo
   {
   	    numero_aleatorio=rand()%10+5;//volta a fazer
   }
   
   string linha;//vai armazenar uma linha na string para moder mostrar
   int i=0;//para ler apenas as linhas que queremos
   User *user;
   cout<<numero_aleatorio<<endl;
   
   //------------gerar a linha aleatoria pra procuara no fich---------
   int numero_para_procurar_fich=rand()%10000+1;;
   arquivo.seekg(0);//garantir que estamos no inicio do arquivo
   //ACHA UMA LINHA ALEATORIA E PERCORRE APARTIR DESSA LINHA
   for(int linhaatual=1;linhaatual<numero_para_procurar_fich;++linhaatual)//vai até que a linha que esta atual seja a linha que desejamos
   {
        if (!getline(arquivo, linha)) //verifica se houve erro
		{
            cout << "Erro durante a leitura da linha " << linhaatual << endl;
        }
   }//e agora o ponteiro esta na linha desejada
   cout<<numero_para_procurar_fich<<endl;
   while(i<numero_aleatorio &&getline(arquivo,linha))//para ler dentro do arquivo ,vai percorrer linha a linha
   {
   	istringstream separador(linha);//vai fazer a  delemitar a linha
   	string nome,local,id,idade;  //vai criar as variaveis para guadar a informação
   	
   	getline(separador,id,'\t');//vai guardar a informação em cada variavel
   	getline(separador,nome,'\t');
   	getline(separador,local,'\t');
   	getline(separador,idade,'\t');
   	
   	//converter para int a string
   	int Idade=stoi(idade);
   	int Id=stoi(id);
   	
   	//vai criar um user com as iformçoes e add a lista do casino
	user=new User(nome,Idade,local,Id);
	Add_USER(user);	
	//cout << "Usuário adicionado: " << nome << ", " << Idade << ", " << local << ", " << Id << endl;
	i++;  //incrementa até chegar ao limite de numero
	
    user = nullptr; //limpa o ponteiro 
   }  
        
   //libera meloria para o ponteiro
	delete user;
	
   arquivo.close();//FECHA O FICH 	
}   
	

list<User*> Casino::Jogadores_Mais_Frequentes(){
    float max_tp = 0;
    list<User*> LUSfreqs;

    for(list<User*>::iterator it = LUS.begin(); it != LUS.end(); it++) {
        if ((*it)->getTempoJogado() > max_tp) {
            max_tp = (*it)->getTempoJogado();
        }
    }

    for(list<User*>::iterator it = LUS.begin(); it != LUS.end(); it++) {
        if ((*it)->getTempoJogado() == max_tp) {
            LUSfreqs.push_back(*it);
            (*it)->Show();
        }
    }
return LUSfreqs;
}

list<User *> Casino::Jogadores_Mais_Ganhos()
{
    float max_ganho = 0;
    list<User*> LUSricos;

    for(list<User*>::iterator it = LUS.begin(); it != LUS.end(); it++) {
        if ((*it)->getTempoJogado() > max_ganho) {
            max_ganho = (*it)->GetPremios();
        }
    }

    for(list<User*>::iterator it = LUS.begin(); it != LUS.end(); it++) {
        if ((*it)->getTempoJogado() == max_ganho) {
            LUSricos.push_back(*it);
            (*it)->Show();
        }
    }

    return LUSricos;
}

list<Maquina *> *Casino::Listar_Tipo(string Tipo, ostream &f )
{
	 list<Maquina*>* LMTipo = new list<Maquina*>;
	for(list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it)
	{
		//cout <<"entrei" <<endl;
        if ((*it)->GET_TIPO() == Tipo) 
      		{
      			LMTipo->push_back(*it);
			}  	
	}
	
	for(list<Maquina *>::iterator it = LMTipo->begin(); it != LMTipo->end(); ++it)
	{
		(*it)->Show();
    	
	}
	
	 return LMTipo;
	
}


void Casino::Listar(float X, ostream &f)
{
    for(list<Maquina*>::iterator it = LM.begin(); it != LM.end(); it++)
        if((*it)->GetProbPremio() > X)
        {
            f << "ID Maquina: " << (*it)->GET_ID_MAQUINA() << endl;
            f << "Probabilidade de ganhar premio: " << (*it)->GetProbPremio() << endl;
        }

}


void Casino::Listar_Probabilidade_Premio()
{
		for(list<Maquina*>::iterator it = LM.begin(); it != LM.end(); it++)
		cout << " A PROBABILIDADE DA MAQUINA  " <<(*it)->GET_NOME_MAQUINA() << " E "<< (*it)->GetProbPremio()<< endl;
	
}


ESTADO Casino::Get_Estado(int id_maq)
{
	Maquina *maq = PesquisarMaquina(id_maq);
	if(maq) cout <<"maquina encontrada"<<endl;
	if(maq->estado==1)
	{
		cout <<"A maquina esta ligada" << endl;
	} else if (maq->estado==0){
		cout << "A maquina esta desligada" << endl;
	} else  {
		cout <<" maquina broken" << endl;
	}
	//return estado->OFF;
}

int Casino::MemoriaTotal() 
{
	
        int tamanhoTotal = sizeof(*this); // Tamanho do objeto Casino
        
		for(list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it)
       	tamanhoTotal += sizeof(*it);
        
    	for(list<User *>::iterator it = LUS.begin(); it != LUS.end(); ++it)
        tamanhoTotal += sizeof(*it);
        
       cout << "memoria total ocupada pelo casino:  " << tamanhoTotal << "bytes" << endl;
       return tamanhoTotal;
       
}


void Casino::Relatorio(string fich_xml) 
{
	 ofstream F(fich_xml.c_str());
	if (!F.is_open()) {
        std::cerr << "Falha ao abrir o arquivo para escrita." << std::endl;
        return;
    }
    
     F << "<CASINO>" << endl;
     for (list<Maquina *>::iterator it = LM.begin(); it != LM.end(); it++) {
        F << "  <MAQUINA>" << std::endl;
        F << "    <ID>" << (*it)->GET_ID_MAQUINA() << "</ID>" << endl;
        F << "    <NOME>" << (*it)->GET_NOME_MAQUINA() << "</NOME>" << endl;
        //F << "   <POSICAO>" << (*it)->GET_POSICAO_MAQUINA() << "</POSICAO>" << endl;
        F << "   <TEMPERATURA>" << (*it)->GET_TEMPERATURA() << "</TEMPERATURA>" << endl;
        F << "   <PROBABILIDADE_PREMIO>" << (*it)->GetProbPremio() << "</PROBABILIDADE_PREMIO>" << endl;
        F << "  </MAQUINA>" << endl;
    }
    
    for (list<User *>::iterator it = LUS.begin(); it != LUS.end(); it++) {
        F << "  <USER>" << std::endl;
        F << "    <NUMERO>" << (*it)->GET_IDPLAYER() << "</NUMERO>" << endl;
        F << "    <NOME>" << (*it)->GET_NOME() << "</NOME>" << endl;
        F << "    <IDADE>" << (*it)->GET_IDADE() << "</IDADE>" << endl;
        F << "    <LOCAL>" << (*it)->GET_LOCAL() << "</LOCAL>" << endl;
        F << "    <NUMERO_PREMIOS>" << (*it)->GetPremios() << "</NUMERO_PREMIOS>" << endl;
        F << "    <SALDO>" << (*it)->GET_SALDO() << "</SALDO>" << endl;
        F << "  </USER>" << std::endl;
    }
    F << "</CASINO>" << endl;
    F.close();
}

void Casino::SubirProbabilidadeVizinhas(Maquina *M_ganhou, float R, list<Maquina *> &lmvizinhas) {

    // Obtém as coordenadas da máquina que ganhou
    int x_ganhou = M_ganhou->GetX();
    float y_ganhou = M_ganhou->GetY();

    // Itera sobre a lista de máquinas para encontrar as vizinhas
    for (list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it) {
        if (*it == M_ganhou) {
            continue;
        }

        // Obtém as coordenadas da máquina atual
        float x_atual = (*it)->GetX();
        float y_atual = (*it)->GetY();

        //pitagoras
        float distancia = sqrt(pow(x_ganhou - x_atual, 2) + pow(y_ganhou - y_atual, 2));
		cout<< "\ndistancia: "<<distancia<<endl;
        if (distancia <= R) {
            (*it)->Aumentar_Probabilidade();
            lmvizinhas.push_back(*it);
        }
    }
    for (list<Maquina *>::iterator it = lmvizinhas.begin(); it != lmvizinhas.end(); ++it) {
   			
   			cout << "esta maquina de coordenadas x: " << (*it)->GetX() << " e y:  "<< (*it)->GetY() << " e uma das maquinas vizinhas" << " e ID:  "<< (*it)->GET_ID_MAQUINA()<< endl;
   
    }
    
}


/*void Casino::SubirProbabilidadeVizinhas(Maquina *M_ganhou, float R, list<Maquina *> &lmvizinhas) 
{
	int x_ganhou = M_ganhou->GetX();
    float y_ganhou = M_ganhou->GetY();

    // Itera sobre a lista de máquinas para encontrar as vizinhas
    for (list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it) {
        if (*it == M_ganhou) {
            continue;
        }
        
        float distancia = sqrt(pow(x_ganhou - x_atual, 2) + pow(y_ganhou - y_atual, 2));
		cout<< "distancia: "<<distancia<<endl;
        
    
        
  }
}

*/


void Casino::AltaProbabilidadePremio(Maquina *M)
{
    L_Alta_Pb.push_back(M);
}

void Casino::AltaAvaria(Maquina *M)
{
    L_Avaria.push_back(M);
}

void Casino::Run()
{
     for (list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it)
            (*it)->Run();

}
	

