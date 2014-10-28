#include <stdio.h>

int main()
{
    int* seq1, *seq2;
    int length1, length2;

    scanf("%i", &length1);
    seq1 = new int[length1];
    for (int i=0; i<length1; i++)
        scanf("%i", &seq1[i]);
    
    scanf("%i", &length2);
    seq2 = new int[length2];
    for (int i=0; i<length2; i++)
        scanf("%i", &seq2[i]);

    //length of Longest Common Sequence for seq1{1,...,i} and seq2{1,...j}
    //general array
    int* lcs_length = new int[length1*length2]();
    //pointers to strings {0, ..., length1 - 1}
    int** lcs = new int*[length2];
    for (int i=0; i < length2; i++)
        lcs[i] = &(lcs_length[i*length1]);

    int to_do = 0;
    
    for (int seq1_it = 0; seq1_it < length1; seq1_it++)
    {
        if (seq1[seq1_it] == seq2[0])
             to_do = 1;
        lcs[0][seq1_it] = to_do;
    }

    to_do = 0;
    for (int seq2_it = 0; seq2_it < length2; seq2_it++)
    {
        if (seq2[seq2_it] == seq1[0])
            to_do = 1;
        lcs[seq2_it][0] = to_do;
    }

    //common dynamic programming cycle
    for (int seq2_it = 1; seq2_it < length2; seq2_it++)
    {
        for (int seq1_it = 1; seq1_it < length1; seq1_it++)
        {
            if (seq1[seq1_it] == seq2[seq2_it])
            {
                lcs[seq2_it][seq1_it] = lcs[seq2_it - 1][seq1_it - 1] + 1;
            }
            else
            {
                int variant1, variant2;
                variant1 = lcs[seq2_it - 1][seq1_it];
                variant2 = lcs[seq2_it][seq1_it - 1];
                lcs[seq2_it][seq1_it] = variant2;
                if (variant1 > variant2)
                {
                    lcs[seq2_it][seq1_it] = variant1;
                }
            }
        }

    }

    printf("%i", lcs[length2-1][length1-1]);
}
