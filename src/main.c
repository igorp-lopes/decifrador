/* Tarefa de decifrar uma cifra
 *
 * Dica: veja em referencia/cifrador.c o codigo-fonte do programa
 * que gerou as cifras que voce precisa decifrar!
 */

#include <stdio.h>

#define TAM_BUFFER 50
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];

int main()
{
  const char palChave[] = "SENHASECRETA";
  // Iteradores
  int i = 0;
  int j = 0;

  // Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);

  // Iteramos pelo texto de entrada até o seu fim
  for (i = 0; (i < TAM_BUFFER) && (buffer_entrada[i] != '\0') && (buffer_entrada[i] != '\n'); i++)
  {

    buffer_saida[i] = decifrador(buffer_entrada[i], palChave[j]); // Obtemos o caracter descriptografado
    j++; // Incrementamos o iterador para selecionarmos o próximo caracter da palavra chave
    if (palChave[j] =='\0') j=0; // Se chegamos ao final da palavra chave, retornamos para o seu início
  }

  buffer_saida[i]='\0'; // Inserimos o caracter de fim da string

  // Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}
