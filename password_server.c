#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("File successfully opened, awaiting incoming requests\n");
    printf("[Connection request from IP {192.168.1.131}]\n");
    printf("[Connection established, waiting for database request]\n\n");

    printf("[Password get-request for <google.com>, username <psareff>]\n");
    printf("Master-password check failure\n");
    printf("Master-password check failure\n");
    printf("Master-password check success\n");
    printf("[Password for <google.com>, <psareff> sent]\n\n");

    printf("[Password post-request for <yandex.ru>, username <mstr_i>\n");
    printf("Master-password check success\n");
    printf("[Password for <yandex.ru>, <mstr_i> written]\n\n");

    printf("[Password delete-request for <google.com>, username <psareff>\n");
    printf("Master-password check success\n");
    printf("[Password for <google.com>, <psareff> deleted]\n\n");

    printf("[Connection stopped with IP {192.168.1.131}]\n");
    sleep(10);
}