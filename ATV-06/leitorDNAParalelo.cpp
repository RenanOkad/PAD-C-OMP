#include <cstdio>
#include <omp.h>
#include <cstdlib>
#include <cstring>
#include <sys/time.h>

int main(int argc, char *argv[])
{
    struct timeval start_time, end_time;
    gettimeofday(&start_time, nullptr);

    omp_set_num_threads(8);
    const char *nomeArquivos[] = {"dna-0.txt", "dna-1.txt", "dna-2.txt", "dna-3.txt",
                                  "dna-4.txt", "dna-5.txt", "dna-6.txt", "dna-7.txt", "dna-8.txt", "dna-9.txt"};
    
#pragma omp parallel
    {
        int thread_id = omp_get_thread_num(); // Obtem o ID da thread

        // Cada thread processa um arquivo diferente
        const char *nomeArquivo = nomeArquivos[thread_id];

        FILE *arquivo = std::fopen(nomeArquivo, "r");

        if (!arquivo)
        {
            std::perror("Erro ao abrir o arquivo");
        }
        else
        {
            char nomeArquivoSaida[256];
            std::strcpy(nomeArquivoSaida, "arquivoDnaSaida");
            std::strcat(nomeArquivoSaida, nomeArquivo);

            FILE *arquivoSaida = std::fopen(nomeArquivoSaida, "w");

            if (!arquivoSaida)
            {
                std::perror("Erro ao abrir o arquivo de saida");
                std::fclose(arquivo);
            }
            else
            {
                char caractere;

                while ((caractere = std::fgetc(arquivo)) != EOF)
                {
                    if (caractere == 'A')
                    {
                        caractere = 'T';
                    }
                    else if (caractere == 'T')
                    {
                        caractere = 'A';
                    }
                    else if (caractere == 'G')
                    {
                        caractere = 'C';
                    }
                    else if (caractere == 'C')
                    {
                        caractere = 'G';
                    }

                    std::fputc(caractere, arquivoSaida);
                }

                std::fclose(arquivo);
                std::fclose(arquivoSaida);
            }
        }
    }

    gettimeofday(&end_time, nullptr);
    long seconds = end_time.tv_sec - start_time.tv_sec;
    long microseconds = end_time.tv_usec - start_time.tv_usec;

    if (microseconds < 0)
    {
        seconds--;
        microseconds += 1000000;
    }

    double elapsed_time = seconds + static_cast<double>(microseconds) / 1000000.0;

    printf("Tempo de execução: %.2f segundos\n", elapsed_time);
    return 0;
}
