#include <iostream>
#include <iomanip> // Para formatar casas decimais

using namespace std;

int main() {
    // Configura o console para mostrar 2 casas decimais em valores monetários
    cout << fixed << setprecision(2);

    // Dados da viagem
    float distancia = 218.0; 
    float velocidade = 100.0; 
    float consumo;

    if (velocidade <= 80) {
       consumo = 16.0;
    } 
    else if (velocidade <= 100) {
    consumo = 14.0;
                    } 
    else if (velocidade <= 110) {
    consumo = 12.5;
                    } 
    else {
    consumo = 11.0;
            } 
    float precoGasolina = 6.0; 

    // Dados do carro
    float tanque = 44.0; 
    float combustivelAtual = tanque / 4; 

    // Cálculos
    float autonomiaAtual = combustivelAtual * consumo;
    float litrosTotaisViagem = distancia / consumo;
    float custoTotal = litrosTotaisViagem * precoGasolina;
    float tempoTotalHoras = distancia / velocidade;

    // Converter tempo
    int horasViagem = (int)tempoTotalHoras;
    int minutosViagem = (int)((tempoTotalHoras - horasViagem) * 60);

    // Horário de saída
    int horaSaida = 7;
    int minutoSaida = 30;

    int horaChegada = (horaSaida + horasViagem);
    int minutoChegada = minutoSaida + minutosViagem;

    if (minutoChegada >= 60) {
        minutoChegada -= 60;
        horaChegada++;
    }
    
    // Ajuste para não passar de 24h
    horaChegada = horaChegada % 24;

    // Saída
    cout << "===== GPS BASICO =====\n";
    cout << "Distancia: " << (int)distancia << " km\n";
    cout << "Velocidade media: " << (int)velocidade << " km/h\n\n";

    cout << "Autonomia atual: " << autonomiaAtual << " km\n";

    if (autonomiaAtual < distancia) {
        float faltaAbastecer = litrosTotaisViagem - combustivelAtual;
        cout << "ALERTA: Voce PRECISA abastecer!\n";
        cout << "Faltam pelo menos: " << faltaAbastecer << " litros para completar o trajeto.\n";
    } else {
        cout << "Combustivel suficiente para o trajeto.\n";
    }

    cout << "\nTempo estimado: " << horasViagem << "h " << minutosViagem << "min\n";
    cout << "Previsao de chegada: " << (horaChegada < 10 ? "0" : "") << horaChegada << ":" 
         << (minutoChegada < 10 ? "0" : "") << minutoChegada << endl;

    cout << "Custo estimado de combustivel: R$ " << custoTotal << endl;

    return 0;
}