#include <stdio.h>

int main()
{
    int* sequence[2];
    int length[2];

    scanf("%i", &length[0]);
    sequence[0] = new int[length[0]];
    for (int i = 0; i < length[0]; ++i)
    {
        scanf("%i", &(sequence[0][i]) );
    }

    scanf("%i", &length[1]);
    sequence[1] = new int[length[1]];
    for (int i = 0; i < length[1]; ++i)
    {
        scanf("%i", &(sequence[1][i]));
    }

    // length of Longest Common Sequence for seq1{1,...,i} and seq2{1,...j}
    // general array
    int* lcs_length = new int[length[0]*length[1]]();
    // pointers to strings {0, ..., length1 - 1}
    int** lcs = new int*[length[1]];
    for (int i = 0; i < length[1]; ++i)
    {
        lcs[i] = &(lcs_length[i*length[0]]);
    }

    int to_do = 0;
    
    for (int seq1_it = 0; seq1_it < length[0]; ++seq1_it)
    {
        if (sequence[0][seq1_it] == sequence[1][0])
             to_do = 1;
        lcs[0][seq1_it] = to_do;
    }

    to_do = 0;
    for (int seq2_it = 0; seq2_it < length[1]; ++seq2_it)
    {
        if (sequence[1][seq2_it] == sequence[0][0])
            to_do = 1;
        lcs[seq2_it][0] = to_do;
    }

    // common dynamic programming cycle
    for (int seq2_it = 1; seq2_it < length[1]; ++seq2_it)
    {
        for (int seq1_it = 1; seq1_it < length[0]; ++seq1_it)
        {
            if (sequence[0][seq1_it] == sequence[1][seq2_it])
            {
                lcs[seq2_it][seq1_it] = lcs[seq2_it - 1][seq1_it - 1] + 1;
            }
            else
            {
                int first, second;
                first = lcs[seq2_it - 1][seq1_it];
                second = lcs[seq2_it][seq1_it - 1];
                lcs[seq2_it][seq1_it] = second;
                if (first > second)
                {
                    lcs[seq2_it][seq1_it] = first;
                }
            }
        }
    }

    printf("%i", lcs[length[1]-1][length[0]-1]);
}
