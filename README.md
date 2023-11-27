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

Arquivo E_1:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/88a8f523-ea40-4778-ac0f-775ea307fe06)

Arquivo E_2:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/602b04f2-d900-4c07-a199-a8307a6668eb)

Arquivo E_3:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/775c625d-c5f3-46dc-bf6d-296292c88920)

Arquivo E_4:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/60c99322-2fa0-4321-9bfc-e224e397b0fc)

Arquivo E_5:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/f3afda5b-22e0-42bb-afc7-b11de129be9d)

Arquivo E_6:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/210308e1-466f-43fa-94fe-84ebfc961072)

Arquivo E_7:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/37bb2506-d981-45fa-9af8-346e950a0f67)

Arquivo E_8:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/313c13f9-2dc7-4a62-b559-c8c12254a745)

Arquivo E_9:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/cc7003f4-aca0-4e68-b0d6-639be4deb7c8)

Arquivo E_10:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/080b38f7-0d98-4b85-9408-80084036ec2c)

Arquivo E_11:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/4fbe4608-f62d-4bc8-9a88-8b167437834a)

Arquivo E_12:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/9d33623d-4a8a-4582-8199-3804c6399909)

Arquivo E_13:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/bc264181-19f4-45dc-90bc-71b4f252bb54)

Arquivo E_14:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/5be74f74-09a8-4745-84e1-ed087537051f)

Arquivo E_15:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/8b775421-21db-48b3-971d-ff4154747b09)

Arquivo E_16:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/dff1cc22-f22d-4971-ac44-5ba343714b07)

Arquivo E_17:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/5e6d5ec4-9bfd-4e44-a4c0-b41ef249b993)

Arquivo E_18:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/b5081358-ccc9-4b47-9e48-c123e77d243e)

Arquivo E_19:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/93f268a6-d412-4885-8162-e42f488cc594)

Arquivo E_20:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/25a9e710-fec4-48f7-890b-c5c32293ae3e)

Arquivo E_21:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/21f290d8-1c99-4a9f-9d0d-7c31dbbb0f0b)

Arquivo E_22:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/1d1af2ab-c56e-4ee8-8f01-d01c38e18d7f)

Arquivo E_23:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/d092b195-f4fc-45d7-a0ac-9a2e77a3add3)

Arquivo E_24:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/ec279d9d-c60c-49df-a67e-424c8157c4b1)

Arquivo E_25:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/1b978086-4506-42b7-89ec-7378c5b9a152)

Arquivo E_26:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/d6455891-c935-4017-97d4-7690cb84f3e6)

Arquivo E_27:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/7f842d5b-0a2d-4589-9738-7baa8546887a)

Arquivo E_28:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/bfebcc45-9ccf-43a2-8fcd-eb280c09648a)

Arquivo E_29:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/c85dfa6a-17a3-4699-8376-7c94a09ebcff)

Arquivo E_30:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/ea25f2c3-952b-4e5d-a05c-633700da98ba)

Arquivo E_31:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/9a5736d4-b411-4cc7-b4e4-4a2fc44399b3)

Arquivo E_32:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/66407e4b-9a1a-4b2e-adb7-3b13ef1eef39)

Arquivo E_33:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/b25ac09f-c3f3-499a-a95e-8e04aae498c9)

Arquivo E_34:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/7573718e-bc99-47b1-ac09-9c53f52b3854)

Arquivo E_35:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/6279390d-1664-4fb4-8fc8-f6935051177a)

Arquivo E_36:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/5fd42989-eee7-45a8-a151-0f936b297d5c)

Arquivo E_37:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/44719915-5846-4de1-a9bd-1e0d6205fdb6)

Arquivo E_38:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/8f5d7953-4ba2-4723-83a1-e5c51982dc2a)

Arquivo E_39:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/32f618b0-4bc0-4d4c-bd11-39c0c3e44e21)

Arquivo E_40:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/6d5b8da7-a113-46c3-b1e0-9c7c5bdfbd14)

Arquivo E_41:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/dbbfed3a-ab44-4738-9c05-9b728844df80)

Arquivo E_42:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/767bef87-3c6f-4dd8-969a-0cec181b7c4b)

Arquivo E_43:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/e9262d2a-c907-4f87-a22d-67496f10cf44)

Arquivo E_44:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/492fb16f-dd7a-4b0a-999a-13cbc0da4716)

Arquivo E_45:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/ca1080ef-dabc-4d03-8733-9143b8721fdd)

Arquivo E_46:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/7567c1ce-8484-4eb3-b212-44cc655ca13c)

Arquivo E_47:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/41a844f9-a971-4540-9910-cef33090ec6d)

Arquivo E_48:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/dc5167e1-f63b-4987-b305-b8f032359058)

Arquivo E_49:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/1d2ac45b-5ebc-4a1f-86d5-fe77a6a20213)

Arquivo E_50:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/c278b7f3-db0c-46e1-91ae-beff5ba2330a)

Arquivo E_51:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/ee578423-09d1-4a10-a3a2-6635ed3473bd)

Arquivo E_52:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/92d51480-f971-4989-a921-831da22d4bdc)

Arquivo E_53:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/302bd931-312a-4600-a853-f0ca536ae535)

Arquivo E_54:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/4d261f48-67ce-4e4b-aa2c-88530b5ed7b5)

Arquivo E_55:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/3e2c59d3-58bf-42c9-9c67-41ba8abdfbae)

Arquivo E_56:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/61e899b9-0867-4b56-b230-84de8e9f126d)

Arquivo E_57:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/86c8d0d4-2fc2-4433-a1a3-057aa2b0ced0)

Arquivo E_58:
![image](https://github.com/VictorMack/ProjetoSO2/assets/62074503/6b91111d-8ca0-4222-97ca-e8e253c0fbc4)


