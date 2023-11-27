# ProjetoSO2

## Integrantes

Nome: Davi Micale - TIA: 32096062

Nome: Victor Rodrigues - TIA: 32273134

Nome: Yuri - TIA: 32230877

Professor: Eduardo Santos

TURMA: 4N

Projeto 2: Escada rolante

## Introdução

O projeto apresenta um código em C que faz analogia ao funcionamento de uma escada rolante de via dupla, que tanto pode ir do lado esquerdo para o direito ou o inverso. O objetivo é  transportar pessoas, as quais possuem indicadores do tempo de chegada na escada e a direção que desejam ir, e obter o tempo que a última pessoa saiu da escada.

### Construção do código

Para a criação do código utilizamos uma struct para armazenar os dados de tempo e direção do passageiro lidas do arquivo txt.
 ![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/dfb1d561-ef1c-4d16-b9b4-4421e5fbd415)

![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/d5863698-8fd0-4ae0-9d27-18b7a52bdaa6)

Na função pessoa, é declarada algumas variáveis auxiliares, para analisar se houve espera, para obter o tempo de espera, tempo atual/final , se o passageiro se moveu antes de entrar ou já entrou direto na escada, uma para armazenar o tempo de espera e a direção inicial.
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/11d894c0-c577-483c-ad89-e8730fb74f35)

Após isso é iniciado o loop para mover as pessoas na escada. O time_to_move serve para analisar se a pessoa já entrou direto na escada ou teve que se mover. Quando há o valor é positivo, caso contrário o valor é negativo. Além da verificação se o passageiro se moveu, analisamos também a direção e se teve espera.
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/49e176f1-f9cb-4177-bdee-b24b371d97fc)

Caso o passageiro tenha tido que se mover e teve espera, o tempo de espera é adicionado no tempo atual, indicada a mudança de direção e espera fica como false, pois o valor de espera já foi incrementado. Sempre que houver espera a pessoa deve ser analisada novamente.
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/9863787c-5ddf-4c88-93d4-052b1af4c9a8)

Em seguida, após o loop é verificado se ainda há espera pendente, caso tenha é adicionado 10 ao tempo final. Por fim, o tempo de saída do último passageiro é impresso.
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/a07b2c53-3780-419f-b891-4121d2595b8f)

## Submissão do código no GitHub
