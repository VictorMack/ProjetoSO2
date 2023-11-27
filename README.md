# ProjetoSO2

## Integrantes

Nome: Davi Micale - TIA: 32096062

Nome: Victor Rodrigues - TIA: 32273134

Nome: Yuri - TIA: 32230877

Professor: Eduardo Santos

Turma: 4N

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

Em seguida, após o loop é verificado se ainda há espera pendente, caso tenha é adicionado 10 ao tempo final. Por fim, o tempo de saída do último passageiro é impressa.

![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/a07b2c53-3780-419f-b891-4121d2595b8f)

## Submissão do código no GitHub

1 – Com repositório no GitHub criado e com a chave que permite escrita deployada , conseguiremos começar a trabalhar no terminal Linux para a conclusão do projeto.
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/817adde4-7ee8-4205-8ccf-48093b599d1c)

2 – Com o arquivo que ira receber o nosso código criado, podemos inserir nele o Código Final. Segue abaixo fotos do código sendo inserido no arquivo.

![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/97a1573b-0bcd-45f2-8325-9ae62f82f4fb)

![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/17ebd040-e890-406e-96a5-6d43c5709a08)

![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/2430c859-63f1-4eb1-ad6f-ff4e88fd219d)

![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/3295508f-ad1c-4587-b6b0-1d9b5599a97a)

3 – Feito isso , podemos mandar o nosso arquivo para nosso repositório GitHub.
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/1e36c55a-fc87-4d65-97eb-dd67b7a843c7)

4 – E por fim mandamos o arquivo compilado para o repositório GitHub também
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/adb97d45-eae1-40fc-8a80-2bbdb1a371b4)

## Evidências

