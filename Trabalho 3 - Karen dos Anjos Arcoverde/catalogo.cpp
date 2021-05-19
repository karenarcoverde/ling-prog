/*****************************************************************************/
/***************************** Arquivo catalogo.cpp **************************/

#include "catalogo.h"

ostream &operator<<(ostream &saida, const Catalogo &catalogo){
    for (int indice_filmes = 0; indice_filmes < catalogo.conjuntoDeFilmes.size(); indice_filmes++)
        saida << catalogo.conjuntoDeFilmes.at(indice_filmes);
    
    return saida;
}

bool operator>(const filme &primfilme, const filme &segfilme){
    if (primfilme.nomeDoFilme > segfilme.nomeDoFilme) 
        return true;

    return false;
}

bool operator==(const filme &primfilme, const filme &segfilme){
    if (primfilme.nomeDoFilme == segfilme.nomeDoFilme) 
        return true;

    return false;
}

bool operator>(const filme &item_filme, const double &notaDoFilme){
    if (item_filme.notaDoFilme > notaDoFilme) 
        return true;

    return false;
}

void Catalogo::ExibeFilmeBemAvaliado(){
    filme filmeBemAvaliado;
    filmeBemAvaliado.notaDoFilme = 0;

    for (int indice_conjunto_filmes = 0; indice_conjunto_filmes < conjuntoDeFilmes.size(); indice_conjunto_filmes++){
        if (conjuntoDeFilmes.at(indice_conjunto_filmes) > filmeBemAvaliado.notaDoFilme) 
            filmeBemAvaliado = conjuntoDeFilmes.at(indice_conjunto_filmes);
    }
    cout << "O filme mais bem avaliado eh:" << filmeBemAvaliado << endl;
}

void Catalogo::RenovarCatalogo(){
    fstream file;
    file.open(nomeArquivo, fstream::out);

    if (!file.is_open()){
        cout << "Arquivo nao existe." << endl;
        exit (0);
    }

    //reescreve com as novas alteracoes 
    for (int indice_conjunto_filmes = 0; indice_conjunto_filmes < conjuntoDeFilmes.size(); indice_conjunto_filmes++){
        file << conjuntoDeFilmes.at(indice_conjunto_filmes).nomeDoFilme << ',';
        file << conjuntoDeFilmes.at(indice_conjunto_filmes).nomeDaProdutora << ',';
        file  << conjuntoDeFilmes.at(indice_conjunto_filmes).notaDoFilme<< endl;
    }

    file.close();
}

Catalogo::Catalogo(){
    vector <filme> conjuntoDeFilmesModificado;
    nomeArquivo = "filmes.txt";

    fstream file;
    string linhaDoFilme;

    file.open(nomeArquivo, fstream::in);

    if (!file.is_open()) {
        cout << "Arquivo nao existe. " << endl;
    }

    else {
        while(getline(file, linhaDoFilme)){

            vector <string> informacoesFilme;

            while(file.good()) {

                string informacaoFilme;

                getline(file, informacaoFilme, ',');
                informacoesFilme.push_back(informacaoFilme);
            }

            filme LinhaFilme;

            LinhaFilme.nomeDoFilme = informacoesFilme.at(0);
            LinhaFilme.nomeDaProdutora = informacoesFilme.at(1);
            LinhaFilme.notaDoFilme = stod(informacoesFilme.at(2));

            conjuntoDeFilmesModificado.push_back(LinhaFilme);
        }

        file.close();

        if (conjuntoDeFilmesModificado.size() <= tamanhoMaximoNumeroDeFilmes) 
            conjuntoDeFilmes = conjuntoDeFilmesModificado;
        else {
            cout << "Passou o tamanho maximo para o numero de filmes!" << endl;
            exit(0);
        }
    }
}

filme *Catalogo::operator()(string nomefilmeEscolhido, string ProdutoraEscolhida){

    if (conjuntoDeFilmes.size() == 0) 
        return NULL;

    for (int indiceconjuntoDeFilmes = 0; indiceconjuntoDeFilmes < conjuntoDeFilmes.size(); indiceconjuntoDeFilmes++) {

        if (conjuntoDeFilmes.at(indiceconjuntoDeFilmes).nomeDoFilme == nomefilmeEscolhido) {
            conjuntoDeFilmes.at(indiceconjuntoDeFilmes).nomeDaProdutora = ProdutoraEscolhida;
            return &conjuntoDeFilmes.at(indiceconjuntoDeFilmes);
        }
    }
    return NULL; 
}

filme *Catalogo::operator()(string nomefilmeEscolhido, double NotaEscolhida){

    if (conjuntoDeFilmes.size() == 0) 
        return NULL;

    for (int indiceconjuntoDeFilmes = 0; indiceconjuntoDeFilmes < conjuntoDeFilmes.size(); indiceconjuntoDeFilmes++) {

        if (conjuntoDeFilmes.at(indiceconjuntoDeFilmes).nomeDoFilme == nomefilmeEscolhido) {
            conjuntoDeFilmes.at(indiceconjuntoDeFilmes).notaDoFilme= NotaEscolhida;
            return &conjuntoDeFilmes.at(indiceconjuntoDeFilmes);
        }
    }
    return NULL;
}

filme *Catalogo::operator()(string nomefilmeEscolhido){
    if (conjuntoDeFilmes.size() == 0) {
        cout << "Catalogo sem nenhum filme " << endl;
        return NULL;
    }

    for (int indiceconjuntoDeFilmes = 0; indiceconjuntoDeFilmes < conjuntoDeFilmes.size(); indiceconjuntoDeFilmes++) {
        if (conjuntoDeFilmes.at(indiceconjuntoDeFilmes).nomeDoFilme == nomefilmeEscolhido) 
            return &conjuntoDeFilmes.at(indiceconjuntoDeFilmes);
    }
    return NULL;
}

const Catalogo &operator-=(Catalogo &catalogo, const filme &filmeEscolhido){

    if (!&filmeEscolhido) 
        cout << "Nao tem o filme " << endl;

    else {
        int indiceFilmeEscolhido;

        for (int indiceconjuntoDeFilmes = 0; indiceconjuntoDeFilmes < catalogo.conjuntoDeFilmes.size(); indiceconjuntoDeFilmes++){
            if (catalogo.conjuntoDeFilmes.at(indiceconjuntoDeFilmes) == filmeEscolhido)
                indiceFilmeEscolhido = indiceconjuntoDeFilmes;
        }

        catalogo.conjuntoDeFilmes.erase(catalogo.conjuntoDeFilmes.begin()+indiceFilmeEscolhido); //apaga o filme escolhido utilizando o metodo erase
    }

    return catalogo;
}


const Catalogo &operator+=(Catalogo &catalogo, const filme &filmeEscolhido){

    if (catalogo.conjuntoDeFilmes.size() == 0) 
        catalogo.conjuntoDeFilmes.push_back(filmeEscolhido);

    else {
        int filmeRepetido = 0;

        for (int indiceconjuntoDeFilmes= 0; indiceconjuntoDeFilmes < catalogo.conjuntoDeFilmes.size(); indiceconjuntoDeFilmes++){
            if (catalogo.conjuntoDeFilmes.at(indiceconjuntoDeFilmes) == filmeEscolhido) 
                filmeRepetido = 1; // para encontrar se o filme escolhido ja esta contido no catalogo
        }

        // so entra nesse if se nao repetido o filme escolhido
        if (filmeRepetido = 0) {
            for (int indiceconjuntoDeFilmes = 0; indiceconjuntoDeFilmes < catalogo.conjuntoDeFilmes.size(); indiceconjuntoDeFilmes++){
                //verifica se o filme escolhido pode entrar na primeira posicao do catalogo
                if (catalogo.conjuntoDeFilmes.at(indiceconjuntoDeFilmes) > filmeEscolhido and indiceconjuntoDeFilmes == 0) {
                    catalogo.conjuntoDeFilmes.insert(catalogo.conjuntoDeFilmes.begin(), filmeEscolhido);
                    break;
                }

                //se pode inserir no meio do filmes o novo filme
                else if (catalogo.conjuntoDeFilmes.at(indiceconjuntoDeFilmes) > filmeEscolhido) {
                    catalogo.conjuntoDeFilmes.insert(catalogo.conjuntoDeFilmes.begin()+indiceconjuntoDeFilmes, filmeEscolhido);
                    break;
                }

                //verifica se o filme escolhido estraria na ultima posicao
                else if (indiceconjuntoDeFilmes == catalogo.conjuntoDeFilmes.size() - 1) {
                    catalogo.conjuntoDeFilmes.push_back(filmeEscolhido);
                    break;
                }
            }
        }
        else if (filmeRepetido = 1)
            cout << "Este filme ja esta contido no catalogo. Tente novamente. " << endl;
    }
    return catalogo;
}

const Catalogo &operator+=(Catalogo &catalogo, const vector <filme> &vetorDeFilmes){

    if (catalogo.conjuntoDeFilmes.size() == 0) 
        catalogo.conjuntoDeFilmes.insert(catalogo.conjuntoDeFilmes.end(),vetorDeFilmes.begin(),vetorDeFilmes.end());

    else if (catalogo.conjuntoDeFilmes.size() + 1 > catalogo.tamanhoMaximoNumeroDeFilmes) 
        cout << "Operacao impossivel, limite maximo atingido." << endl;

    else {
        for (int indiceEntrada = 0; indiceEntrada < vetorDeFilmes.size(); indiceEntrada++){
            bool achouFilmeIgual = false;
            for (int indiceconjuntoDeFilmes = 0; indiceconjuntoDeFilmes < catalogo.conjuntoDeFilmes.size(); indiceconjuntoDeFilmes++){
                if (catalogo.conjuntoDeFilmes.at(indiceconjuntoDeFilmes) == vetorDeFilmes.at(indiceEntrada)) 
                    achouFilmeIgual = true;
            }

            if (!achouFilmeIgual) 
                catalogo += vetorDeFilmes.at(indiceEntrada);
            else 
                cout << "Filme " << vetorDeFilmes.at(indiceEntrada).nomeDoFilme << " ja existe. Se quiser, edite seus dados." << endl;
        }
    }
    return catalogo;
}
