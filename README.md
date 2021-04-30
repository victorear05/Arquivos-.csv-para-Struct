# Arquivos-.csv-para-Struct
Programa que lê um arquivo .csv do tipo: | %s;%s;%s;%s;%d;%d;%d;%;%d;%d\n |e o coloca em uma struct, têm a opção indexação e a opção consulta.  
  
Com alguns ajustes o programa pode ser usado para outros modelos de .csv.  
Esse algoritmo se baseia em:  
  
1 - Ler um arquivo .csv dado pelo usuário e o salvar em uma struct de Dados  
2 - Indexar os arquivos da struct de Dados em uma struct de busca (possui apenas um código e seu índice)  
3 - Ordenar os dados da struct indexada  
4 - A partir do código fazer uma busca binária na struct Indexada, ler sua posição, e mostrar os dados da struct que possui tal código  
