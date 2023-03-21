#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cJSON.h"

#define TAM 30 // número de dias do mês

int main()
{
    cJSON *json, *faturamento_diario_json;
    float faturamento_diario[TAM];
    float soma_faturamento = 0;
    int i, dias_acima_media = 0;
    float media_faturamento, menor_faturamento, maior_faturamento;
    FILE *fp;

    //abrindo o arquivo JSON
    fp = fopen("faturamento.json", "r");
    if(fp == NULL){
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buffer = (char*) malloc(size + 1);
    fread(buffer, 1, size, fp);
    fclose(fp);
    buffer[size] = '\0';

    json = cJSON_Parse(buffer);
    if(json == NULL){
        printf("Erro ao parsear arquivo JSON.\n");
        return 1;
    }
    
    faturamento_diario_json = cJSON_GetObjectItemCaseSensitive(json, "faturamento_diario");
    if(cJSON_IsArray(faturamento_diario_json)){
        int size = cJSON_GetArraySize(faturamento_diario_json);
        if(size != TAM){
            printf("Número de elementos no array não corresponde ao número de dias do mês.\n");
            return 1;
        }
        for(i=0; i<size; i++){
            faturamento_diario[i] = cJSON_GetArrayItem(faturamento_diario_json, i)->valuedouble;
            soma_faturamento += faturamento_diario[i];
        }
    }
    else{
        printf("Erro ao obter array de faturamento diário.\