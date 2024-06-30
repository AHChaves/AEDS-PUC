#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <fstream> // Para manipulação de arquivos
#include <stdlib.h>
#include <iomanip>

using namespace std;

class AHP
{
private:
    int n, m;
    vector<string> criteria;
    vector<vector<double>> criteriaMatrix;
    vector<double> criteriaWeights;
    vector<string> alternatives;
    vector<vector<vector<double>>> alternativeMatrices;
    vector<double> alternativeWeights;

public:
    AHP() {}
    ~AHP() {}

    // Getters
    int getN() const { return n; }
    int getM() const { return m; }
    vector<string> getCriteria() const { return criteria; }
    vector<double> getCriteriaWeights() const { return criteriaWeights; }
    vector<string> getAlternatives() const { return alternatives; }
    vector<double> getAlternativeWeights() const { return alternativeWeights; }

    // Setters
    void setN(int value) { n = value; }
    void setM(int value) { m = value; }
    void setCriteria(const vector<string> &value) { criteria = value; }
    void setCriteriaWeights(const vector<double> &value) { criteriaWeights = value; }
    void setAlternatives(const vector<string> &value) { alternatives = value; }
    void setAlternativeWeights(const vector<double> &value) { alternativeWeights = value; }


    void inputCriteria()
    { // define the names of the criterias
        getchar();

        criteria.resize(n);

        for (int i = 0; i < n; ++i)
        {
            cout << "Digite o nome do criterio " << i + 1 << ": ";
            getline(cin, criteria[i]);
        }

        system("cls");
    }

    void inputCriteriaMatrix()
    { // Create the matrix of criterias

        double value;

        criteriaMatrix.resize(n, vector<double>(n, 0.0));

        cout << "Digite a matriz de comparação dos critérios (" << n << "x" << n << "):" << endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if (i == j)
                {
                    criteriaMatrix[i][j] = 1;
                }
                else
                {
                    cout << "Digite o grau de dominacao que " << criteria[i] << " exerce sobre "
                         << criteria[j] << ": ";
                    cin >> value;
                    criteriaMatrix[i][j] = value;
                    criteriaMatrix[j][i] = 1 / value;
                }
            }
        }

    }

    void inputAlternatives()
    { // define the names of the products we are chosing
        getchar();

        alternatives.resize(m);

        for (int i = 0; i < m; i++)
        {
            cout << "Digite o nome da alternativa " << i + 1 << ": ";
            getline(cin, alternatives[i]);
        }

        system("cls");
    }

    void inputAlternativeMatrices()
    { // create the alternative/products matrices

        double value;
        alternativeMatrices.resize(n, vector<vector<double>>(m, vector<double>(m, 0.0)));

        for (int i = 0; i < n; i++)
        {
            cout << "Digite a matriz de comparação para o critério " << criteria[i] << " (" << m << "x" << m << "):" << endl;

            for (int j = 0; j < m; j++)
            {
                for (int k = j; k < m; k++)
                {
                    if (j == k)
                    {
                        alternativeMatrices[i][j][k] = 1;
                    }
                    else
                    {
                        cout << "Digite o grau de dominacao que " << alternatives[j] << " exerce sobre "
                             << alternatives[k] << ": ";
                        cin >> value;
                        alternativeMatrices[i][j][k] = value;
                        alternativeMatrices[i][k][j] = 1 / value;
                    }
                }
            }
        }

        system("cls");
    }

    void calculateCriteriaWeights()
    { // calculate the wights of the criterias

        criteriaWeights.resize(n, 0.0);

        vector<double> columnSums(n, 0.0);

        for (int i = 0; i < n; i++)
        { // sum the columns values
            for (int j = 0; j < n; j++)
            {
                columnSums[i] += criteriaMatrix[j][i];
            }
        }

        for (int i = 0; i < n; ++i)
        { // normalize the matrix
            for (int j = 0; j < n; ++j)
            {
                criteriaMatrix[i][j] /= columnSums[j];
            }
        }

        for (int i = 0; i < n; i++)
        { // create the weights based in the mean of the lines
            double sum = 0.0;
            for (int j = 0; j < n; j++)
            {
                sum += criteriaMatrix[i][j];
            }
            criteriaWeights[i] = sum / n;
        }
    }

    void calculateAlternativeWeights()
    { // Calculate the weights of the matrix of alternatives
        alternativeWeights.resize(m, 0.0);

        for (int i = 0; i < n; i++)
        {

            vector<double> columnSums(m, 0.0);
            vector<double> localWeights(m, 0.0);

            for (int j = 0; j < m; j++)
            { // sum the columns
                for (int k = 0; k < m; k++)
                {
                    columnSums[j] += alternativeMatrices[i][k][j];
                }
            }

            for (int j = 0; j < m; j++)
            { // normalize the matrix
                for (int k = 0; k < m; k++)
                {
                    alternativeMatrices[i][j][k] /= columnSums[k];
                }
            }

            for (int j = 0; j < m; j++)
            { // make the mean of the lines of the matrix
                double sum = 0.0;
                for (int k = 0; k < m; k++)
                {
                    sum += alternativeMatrices[i][j][k];
                }
                localWeights[j] = sum / m;
            }

            for (int j = 0; j < m; j++)
            { // multiply by the criteria weights to find the best alternative
                alternativeWeights[j] += criteriaWeights[i] * localWeights[j];
            }
        }
    }

    double calculateConsistencyIndex(const vector<vector<double>> &matrix, const vector<double> &weights)
    {
        vector<double> lambda(n, 0.0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                lambda[i] += matrix[i][j] * weights[j];
            }
            lambda[i] /= weights[i];
        }

        double lambdaMax = 0.0;
        for (double val : lambda)
        {
            lambdaMax += val;
        }
        lambdaMax /= n;

        return (lambdaMax - n) / (n - 1);
    }

    bool checkConsistency(const vector<vector<double>> &matrix, const vector<double> &weights)
    {
        double ci = calculateConsistencyIndex(matrix, weights);
        double ri[] = {0, 0, 0.58, 0.90, 1.12, 1.24, 1.32, 1.41, 1.45, 1.49, 1.51};
        double cr;

        if(matrix.size() <= 2){
            cr = 0;
        }
        else if (matrix.size() <= 10){
            cr = ci / ri[matrix.size()-1];
        }
        else
            cr = ci / ri[10];

        cout << "Razão de Consistência (CR): " << cr << endl;

        return (cr < 0.1) and (cr >= 0);
    }

    bool InsertAHP()
    {
        system("cls");

        cout << "Inform the number of criterias: ";
        cin >> this->n;

        inputCriteria();
        inputCriteriaMatrix();
        calculateCriteriaWeights();
        if (!checkConsistency(criteriaMatrix, criteriaWeights))
            return false;

        cout << "Press any key to continue";
        getch();

        system("cls");

        cout << "Inform the number of alternatives: ";
        cin >> this->m;

        inputAlternatives();
        inputAlternativeMatrices();
        calculateAlternativeWeights();

        for (int i = 0; i < n; i++)
        {
            if (!checkConsistency(alternativeMatrices[i], alternativeWeights))
                return false;
        }

        displayResults();
        return true;
    }

    void displayResults()
    {
        cout << "\nPesos dos Critérios:" << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << criteria[i] << ": " << criteriaWeights[i] << endl;
        }

        cout << "\nPesos das Alternativas:" << endl;
        for (int i = 0; i < m; ++i)
        {
            cout << alternatives[i] << ": " << alternativeWeights[i] << endl;
        }
    }
};

void saveAHPData(const vector<AHP> &ahp, const string &filename)
{
    ofstream file(filename);

    if (!file.is_open())
    {
        cout << "Erro ao abrir o arquivo para salvar." << endl;
        return;
    }

    for (const auto &instance : ahp)
    {
        file << instance.getN() << " " << instance.getM() << endl;

        // Salvar critérios
        for (const auto &criterion : instance.getCriteria())
        {
            file << criterion << endl;
        }

        // Salvar pesos dos critérios
        for (const auto &CWeights : instance.getCriteriaWeights())
        {
            file << CWeights << endl;
        }
        file << endl;

        // Salvar alternativas
        for (const auto &alternative : instance.getAlternatives())
        {
            file << alternative << endl;
        }

        // Salvar pesos das alternativas
        for (const auto &alternativeW : instance.getAlternativeWeights())
        {
            file << alternativeW << endl;
        }
        file << endl;
    }

    file.close();
    cout << "Dados salvos com sucesso em " << filename << endl;
}

void loadAHPData(vector<AHP> &ahp, const string &filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return;
    }

    ahp.clear(); // Limpa o vetor de AHPs para começar do zero

    string line;
    while (getline(file, line)) {
        AHP instance;
        int n, m;
        stringstream ss(line);

        if (!(ss >> n >> m)) {
            cout << "Erro ao ler os valores de n e m." << endl;
            continue;
        }

        instance.setN(n);
        instance.setM(m);

        // Ler critérios
        vector<string> criteria(n);
        for (int i = 0; i < n; ++i) {
            if (!getline(file, criteria[i])) {
                cout << "Erro ao ler os nomes dos critérios." << endl;
                continue;
            }
        }
        instance.setCriteria(criteria);

        // Ler pesos dos critérios
        vector<double> criteriaWeights(n);
        for (int i = 0; i < n; ++i) {
            if (!(file >> criteriaWeights[i])) {
                cout << "Erro ao ler os pesos dos critérios." << endl;
                continue;
            }
        }
        instance.setCriteriaWeights(criteriaWeights);

        // Ler alternativas
        vector<string> alternatives(m);
        for (int i = 0; i < m; ++i) {
            if (!getline(file, alternatives[i])) {
                cout << "Erro ao ler os nomes das alternativas." << endl;
                continue;
            }
        }
        instance.setAlternatives(alternatives);

        // Ler pesos das alternativas
        vector<double> alternativeWeights(m);
        for (int i = 0; i < m; ++i) {
            if (!(file >> alternativeWeights[i])) {
                cout << "Erro ao ler os pesos das alternativas." << endl;
                continue;
            }
        }
        instance.setAlternativeWeights(alternativeWeights);

        ahp.push_back(instance);
    }

    file.close();
    cout << "Dados carregados com sucesso de " << filename << endl;
}

int main()
{
    system("cls");
    int option;
    string file = "dados.txt";

    vector<AHP> ahp;

    loadAHPData(ahp, file);

    do
    {
        cout << "Choose a option:" << endl;
        cout << "[1] Add an AHP" << endl;
        cout << "[2] List cadastrated AHPs" << endl;
        cout << "[0] Exit" << endl;
        cout << "> ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            AHP aux;
            if (aux.InsertAHP())
            {
                ahp.push_back(aux);
            }
            else
            {
                cout << "The matrix is inconsistent!!!" << endl;
            }
            break;
        }
        case 2:
            for (int i = 0; i < ahp.size(); i++)
            {
                cout << "AHP #" << i + 1 << " Results:" << endl;
                ahp[i].displayResults();
                cout << endl;
            }
            break;
        case 0:
            break;
        default:
            cout << "Invalid Option!!!" << endl;
            break;
        }

    } while (option != 0);

    saveAHPData(ahp, file);

    return 0;
}
