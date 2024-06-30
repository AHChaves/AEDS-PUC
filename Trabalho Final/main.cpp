#include <iostream>
#include <vector>
#include <string>
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

        system("clear");
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

        system("clear");
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

        system("clear");
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
        system("clear");

        cout << "Inform the number of criterias: ";
        cin >> this->n;

        inputCriteria();
        inputCriteriaMatrix();
        calculateCriteriaWeights();
        if (!checkConsistency(criteriaMatrix, criteriaWeights))
            return false;

        cout << "Press any key to continue";
        fflush(stdin);
        cin.get();

        system("clear");

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

// Função para salvar todos os dados de um vetor de objetos AHP em um arquivo
void saveDataToFile(const vector<AHP> &ahps, const string &filename)
{
    ofstream file(filename);
    if (file.is_open())
    {
        for (size_t index = 0; index < ahps.size(); ++index)
        {
            const AHP &ahp = ahps[index];
            file << "AHP #" << index + 1 << endl;

            file << "Critérios e Pesos:\n";
            vector<string> criteria = ahp.getCriteria();
            vector<double> criteriaWeights = ahp.getCriteriaWeights();

            for (size_t i = 0; i < criteria.size(); ++i)
            {
                file << criteria[i] << ": " << criteriaWeights[i] << endl;
            }

            file << "\nAlternativas e Pesos:\n";
            vector<string> alternatives = ahp.getAlternatives();
            vector<double> alternativeWeights = ahp.getAlternativeWeights();

            for (size_t i = 0; i < alternatives.size(); ++i)
            {
                file << alternatives[i] << ": " << alternativeWeights[i] << endl;
            }

        }
        file.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo para salvar os dados.\n";
    }
}

// Função para ler os dados de um arquivo e carregar em um vetor de objetos AHP
void loadDataFromFile(vector<AHP> &ahps, const string &filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        int n, m;
        AHP ahp;
        vector<string> criteria;
        vector<double> criteriaWeights;
        vector<string> alternatives;
        vector<double> alternativeWeights;

        while (getline(file, line))
        {
            if (line.find("AHP #") != string::npos)
            {
                if (!criteria.empty() || !alternatives.empty())
                {
                    ahp.setCriteria(criteria);
                    ahp.setCriteriaWeights(criteriaWeights);
                    ahp.setAlternatives(alternatives);
                    ahp.setAlternativeWeights(alternativeWeights);
                    ahps.push_back(ahp);
                }
                criteria.clear();
                criteriaWeights.clear();
                alternatives.clear();
                alternativeWeights.clear();
                n = 0;
                m = 0;
            }
            else if (line.find("Critérios e Pesos:") != string::npos)
            {
                while (getline(file, line) && !line.empty() && line.find("Alternativas e Pesos:") == string::npos)
                {
                    size_t colonPos = line.find(":");
                    if (colonPos != string::npos)
                    {
                        string criteriaName = line.substr(0, colonPos);
                        double weight = stod(line.substr(colonPos + 1));
                        criteria.push_back(criteriaName);
                        criteriaWeights.push_back(weight);
                        n++;
                    }
                }
            }
            if (line.find("Alternativas e Pesos:") != string::npos)
            {
                while (getline(file, line) && !line.empty() && line.find("AHP #") == string::npos)
                {
                    size_t colonPos = line.find(":");
                    if (colonPos != string::npos)
                    {
                        string alternativeName = line.substr(0, colonPos);
                        double weight = stod(line.substr(colonPos + 1));
                        alternatives.push_back(alternativeName);
                        alternativeWeights.push_back(weight);
                        m++;
                    }
                }
            }
        }

        if (!criteria.empty() || !alternatives.empty())
        {
            ahp.setN(n);
            ahp.setM(m);
            ahp.setCriteria(criteria);
            ahp.setCriteriaWeights(criteriaWeights);
            ahp.setAlternatives(alternatives);
            ahp.setAlternativeWeights(alternativeWeights);
            ahps.push_back(ahp);
        }

        file.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo para ler os dados.\n";
    }
}

int main()
{
    system("clear");
    int option;
    string file = "dados.txt";

    vector<AHP> ahp;

    loadDataFromFile(ahp, file);

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

    saveDataToFile(ahp, file);

    return 0;
}
