/* Tarefa de decifrar uma cifra
 *
 * Dica: veja em referencia/cifrador.c o codigo-fonte do programa
 * que gerou as cifras que voce precisa decifrar!
 */

#include <stdio.h>

#define TAM_BUFFER 50
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];

// Função que recebe um caracter texto criptografado e um caracter da palavra chave e retorna o caracter descriptografado
char decifrador(char charOrig, char charCifra)
{

  // Se o caracter em questão é uma das letras do alfabeto
  if ( (charOrig >= 'A') && (charOrig <= 'Z') )
  {
    // Obtemos as posições dos caracteres no alfabeto (1 - 26)
    char posCharOrig = charOrig - 'A';
    char posCharCifra = charCifra - 'A';

    // Voltamos posCharCifra posições no caracter posCharOrig e salvamos o caracter resultante
    char charMod = 'A'+( posCharOrig - posCharCifra + ('Z'-'A'+1) ) % ('Z'-'A'+1);
  }
  // Do contrário retornamos o caracter sem alteração
  else
  {
    return charOrig;
  }
  

}

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
