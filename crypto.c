#include <stdio.h>
#include <string.h>

void crypt1(void);
void crypt2(void);

int main()
{
    int choix = 0;
    char rep;

    do
    {
        printf("Bienvenue dans notre programme de cryptographie\n\nOption 1 : Cryptage par decalage\nOption 2 : Cryptage par decalage alphabetique\n");
        scanf("%d",&choix);
        while (choix != 1 && choix != 2)
        {
            printf("Erreur de saisie, veuillez entrer une valeur correcte : ");
            fflush(stdin);
            scanf("%d",&choix);
        }
        switch (choix)
        {
            case 1 :
                crypt1();
                break;
            case 2 :
                crypt2();
                break;
        }
        printf("Voulez-vous crypter une nouvelle phrase ? (o/n) : ");
        scanf(" %c",&rep);
        printf("\n");
    }while (rep == 'o');
    return (0);
}

void crypt1(void)
{
    char phrase[27];
    int i,decalage,cpt;

    cpt = 0;
    i = 0;
    printf("Saisir une phrase de 26 lettres au plus sans ponctuation\n");
    fflush(stdin);
    gets(phrase); /* saisie de la phrase a crypter */
    while (phrase[i] != '\0' && i <= 25)
    {
        cpt = cpt + 1;
        i = i + 1;
    } /* calcul du nombre de lettres */
    for (i=0; i<cpt; i++)
    {
        if (phrase[i] != 32)
        {
            while (phrase[i] < 65 || phrase[i] > 122 || phrase[i] > 90 && phrase[i] < 97)
            {
                printf("Erreur de saisie, veuillez saisir une phrase constituee de lettres uniquement : ");
                gets(phrase);
                i = i + 1;
            }
        }
        else
            phrase[i] = '%'; /* remplacement des espaces par des '%' */
    } /* verification de la saisie par rapport a son contenu (lettres uniquement acceptees) */
    while (strlen (phrase) > 26 || strlen(phrase) <= 0)
    {
        if (strlen (phrase) > 26)
            printf("Erreur de saisie, veuillez saisir une phrase de 26 lettres au plus : ");
        else
            printf("Erreur de saisie, veuillez saisir une phrase constituee de lettres : ");
        gets(phrase);
    } /* verification de la taille de la phrase */
    printf("Saisir le decalage desire : ");
    fflush(stdin);
    scanf("%d",&decalage);
    while (decalage < 1 || decalage > 25)
    {
        printf("Intervalle de decalage invalide, veuillez le resaisir : ");
        fflush(stdin);
        scanf("%d",&decalage);
    } /* verification de la saisie du decalage */
    for (i=0;i<cpt;i++)
    {
        if (phrase[i] != '%')
            phrase[i] = phrase[i] + decalage;
    } /* cryptage lettre par lettre */
    printf("votre phrase cryptee est : %s\n",phrase);
    for (i=0;i<cpt;i++)
    {
        if (phrase[i] != '%')
            phrase[i] = phrase[i] - decalage;
        else
            phrase[i] = ' ';
    } /* decryptage lettre par lettre */
    printf("votre phrase decryptee est : %s\n",phrase);
}

void crypt2(void)
{
    char phrase[27];
    char cle[27],alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char alphabetmaj[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i,cpt,j,true = 0;

    cpt = 0;
    i = 0;
    printf("Saisir une phrase de 26 lettres au plus sans ponctuation\n");
    fflush(stdin);
    gets(phrase); /* saisie de la phrase a crypter */
    while (phrase[i] != '\0' && i <= 25)
    {
        cpt = cpt + 1;
        i = i + 1;
    } /* calcul du nombre de lettres */
    for (i=0; i<cpt; i++)
    {
        if (phrase[i] != 32)
            while (phrase[i] < 65 || phrase[i] > 122 || phrase[i] > 90 && phrase[i] < 97)
            {
                printf("Erreur de saisie, veuillez saisir une phrase constituee de lettres uniquement : ");
                gets(phrase);
                i = i + 1;
            }
        else
            phrase[i] = '%'; /* remplacement des espaces par des '%' */
    } /* verification de la saisie par rapport a son contenu (lettres uniquement acceptees) */
    while (strlen (phrase) > 26 || strlen(phrase) <= 0)
    {
        if (strlen (phrase) > 26)
            printf("Erreur de saisie, veuillez saisir une phrase de 26 lettres au plus : ");
        else
            printf("Erreur de saisie, veuillez saisir une phrase constituee de lettres : ");
        gets(phrase);
    } /* verification de la taille de la phrase */
    printf("Saisir un alphabet cle afin de crypter votre phrase de 26 lettres au plus sans ponctuation : ");
    gets(cle); /* saisie de l'alphabet cle */
    for (i=0;i<cpt;i++)
    {
        for (j=0;j<26;j++)
        {
            if (phrase[i] == alphabet[j])
            {
                phrase[i] = cle[j];
                j = 26;
            }
            else if (phrase[i] == alphabetmaj[j])
            {
                phrase[i] = cle[j];
                j = 26;
                true = 1;
            }
        }
    } /* cryptage de la phrase */
    printf("phrase cryptee : %s\n", phrase);
    for (i=0;i<cpt;i++)
    {
        for (j=0;j<26;j++)
        {
            if (phrase[i] == cle[j] && true == 1)
            {
                phrase[i] = alphabetmaj[j];
                j = 26;
            }
            else if (phrase[i] == cle[j])
            {
                phrase[i] = alphabet[j];
                j = 26;
            }
            else if (phrase[i] == '%')
            {
                phrase[i] = ' ';
            }
        }
    } /*decryptage de la phrase*/
    printf("phrase decryptee : %s\n",phrase);
}
