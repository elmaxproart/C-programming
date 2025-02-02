/*#include <stdio.h>
#include <time.h>

int main( int argc, char * argv[] ) {

    time_t timestamp = time(NULL);
    struct tm * timeInfos = localtime( & timestamp );

    printf( "Date and local time : %s\n", asctime( timeInfos ) );

    return 0;
}
*//*
#include <stdio.h>
#include <time.h>

int main( int argc, char * argv[] ) 
{

    time_t timestamp = time( NULL );
    struct tm * timeInfos = gmtime( & timestamp );

    printf( "Date and UTC time : %04d/%02d/%02d %02d:%02d:%02d\n",
        timeInfos->tm_year+1900, timeInfos->tm_mon+1, timeInfos->tm_mday,
        timeInfos->tm_hour, timeInfos->tm_min, timeInfos->tm_sec
    );
            
    return 0;
}*/
#include <stdio.h>
#include <time.h>

/*int main( int argc, char * argv[] ) {

    struct tm myDate;
    myDate.tm_mday+0 ;
    myDate.tm_mon  +1;
    myDate.tm_year -1900;   // Date == April 6, 2014
    myDate.tm_hour ;
    myDate.tm_min ;
    myDate.tm_sec ;     // Time == 12:30:15

    time_t timestamp = mktime( & myDate );
    printf( "Timestamp == %ld\n", timestamp );
    
    const char * strDate =ctime ( & timestamp  );
    printf( "Initial time == %s\n", strDate );
            
    return 0;
}*/
/*
#include <stdio.h>
#include <time.h>

int main( int argc, char * argv[] ) {

    const char * months[] = { 
        "Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet",
        "Août", "Septembre", "Octobre", "Novembre", "Décembre"
    };
    const char * days[] = {
        "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"
    };

    time_t timestamp = time( NULL );
    struct tm * now = localtime( & timestamp );

    printf( "%4d-%02d-%02d %02d:%02d:%02d\n", 
        now->tm_year+1900, now->tm_mon+1, now->tm_mday,
        now->tm_hour, now->tm_min, now->tm_sec );
     
    printf( "Nous sommes le %s %d %s %d\n",
            days[now->tm_wday], now->tm_mday,
            months[now->tm_mon], now->tm_year+1900);
                
    return 0;
}*//*

#include <stdio.h>
#include <time.h>
/void initialisation_periode( )
{
    struct tm * timeInfos;
   time_t TIMESTAMP =time(NULL);
   timeInfos=gmtime(&TIMESTAMP);
   
   printf( " localetime si :%04d/%02d/%02d %02d:%02d:%02d\n",
        timeInfos->tm_year+1900, timeInfos->tm_mon+1, timeInfos->tm_mday,
        timeInfos->tm_hour, timeInfos->tm_min, timeInfos->tm_sec);
      
}
int main()
{
   initialisation_periode( );
}*/
/*
                        fscanf(f, "%d;%s\n;%s\n", &em.num_emprunt, em.date_emprunt, em.date_Retour) ;
                        printf("\t\tEntrez la date d'emprunt (jj/mm/AAAA):\n\t\tRéponse:_");
                        scanf("%10s", em.date_emprunt);
                        getchar();
                        printf("\t\tEntrez la date de retour (jj/mm/AAAA):\n\t\tRéponse:_");
                        scanf("%10s", em.date_Retour);
                        getchar();
                        em.num_emprunt=genererCodeRetrait();
                        getchar();*/



#include <stdio.h>


int main() {
    char password[20];
    int i = 0;
    char c;

    printf("Enter password: ");
    
    while(1) {
        c = getch();
        
        if(c == 13) {  // 13 is the ASCII code for Enter key
            password[i] = '\0';  // Terminate the string
            break;
        }
        else if(c == 8) {  // 8 is the ASCII code for Backspace key
            if(i > 0) {
                i--;
                printf("\b \b");  // Erase the previous character from console
            }
        }
        else {
            password[i] = c;
            i++;
            printf("*");  // Print * instead of the actual character
        }
    }

    printf("\nPassword entered: %s", password);

    return 0;
}
