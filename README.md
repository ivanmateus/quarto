# Quarto
'Quarto' é um jogo de tabuleiro projetado pelo game designer Blaise Muller. A versão implementada utiliza valores hezadecimais de 0 a 15 (0 a F) como entradas visto que, em binário, possuem 4 dígitos (0000 a 1111), de forma que cada dígito corresponde a uma 'qualidade' diferente e cada número, uma 'peça diferente. Nesta versão, implementada em C, também é possível jogar contra uma inteligência artificial que é baseada no algoritmo minimax.

#Compilando o programa
Para compilar o programa é necessário ter o GCC instalado no micro utilizado. Após isso, abra o terminal, vá para o diretório em que os arquivos acima estão salvos e digite o seguinte comando:

$ gcc main.c board.c game.c player.c ai.c -o main}

Para compilar usando o Code::Blocks, abra um projeto vazio 'empty project', então vá em Project -> Add files..., selecione todos os arquivos .c e .h, clique em 'Open' e em 'Ok' na janela seguinte. Por fim,  tecle Ctrl+F9 para compilar o programa.

#Executando o programa
Caso queira executar o programa normalmente, basta digitar no terminal o seguinte comando: 

$ ./main

Esse comando abre um menu que exibe duas opções ao usuário (jogar no modo multiplayer ou contra a IA). Entretanto, caso queira executar o programa teste com valores previamente estabelecidos, basta digitar:

$ ./main -test

Caso esteja utilizando o compilador Code::Blocks, basta clicar no botão 'Run', na barra de tarefas, ou teclar Ctrl+F10. Caso queira executar o programa-teste, vá em Project -> Set programs' arguments... No campo 'Program arguments', digite "-test" em seguida, compile e execute o programa como nas instruções dadas acima.

#Autor
Ivan Mateus de Lima Azevedo - https://github.com/ivanmateus
