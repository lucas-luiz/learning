#include <stdio.h>

int main()
{
    int i, peso, quant_faixa1 = 0, quant_faixa2 = 0, quant_faixa3 = 0, quant_faixa4 = 0;
    float p_total_faixa1 = 0, p_total_faixa2 = 0, p_total_faixa3 = 0, p_total_faixa4 = 0, m_1, m_2, m_3, m_4;
    for (i = 0; i < 3; i++)
    {
        printf("Insira o peso da pessoa %i em Kg: ", i);
        scanf("%i", &peso);
        if (peso >= 1 && peso <= 10)
        {
            p_total_faixa1 = p_total_faixa1 + peso;
            quant_faixa1++;
        }
        else if (peso >= 11 && peso <= 20)
        {
            p_total_faixa2 = p_total_faixa2 + peso;
            quant_faixa2++;
        }
        else if (peso >= 21 && peso <= 30)
        {
            p_total_faixa3 = p_total_faixa2 + peso;
            quant_faixa3++;
        }
        else
        {
            p_total_faixa4 = p_total_faixa2 + peso;
            quant_faixa4++;
        }
    }
    m_1 = quant_faixa1 != 0 ? (p_total_faixa1 / quant_faixa1) : 0;
    m_2 = quant_faixa2 != 0 ? (p_total_faixa2 / quant_faixa2) : 0;
    m_3 = quant_faixa3 != 0 ? (p_total_faixa3 / quant_faixa3) : 0;
    m_4 = quant_faixa4 != 0 ? (p_total_faixa4 / quant_faixa4) : 0;

    printf("\nMEDIAS TOTAIS DE CADA FAIXA ETARIA\nFAIXA 1: %.2f\nFAIXA 2: %.2f\nFAIXA 3: %.2f\nFAIXA 4: %.2f\n", m_1, m_2, m_3, m_4);

    return 0;
}
