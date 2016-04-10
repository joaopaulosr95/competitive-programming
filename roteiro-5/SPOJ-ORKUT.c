#include <stdio.h>
#include <string.h>


typedef struct {
  char nameProfile[33];
  int cod, edgPessoa[33];
} profile;

int n, ge[33];
profile friends[33];
int n0, gz[33];
int n1, out[33];

int search(char *nameProfile) {
  int i;

  for (i=0; i<n; i++)
    if (!strcmp(nameProfile, friends[i].nameProfile))
      return i;

  fprintf(stderr, "Nome nao existe: %s\n", nameProfile);
  return -1;
}

int main(void) {
  int i, j, cod, i0, i1, aux = 1;
  char nameProfile[33];

  while (scanf("%d", &n)==1 && n) {

    for (i=0; i<n; i++) {
      scanf(" %s", friends[i].nameProfile);
      friends[i].cod = 0;

    }
    memset(ge, 0, sizeof(ge));

    for (j=0; j<n; j++) {

      scanf(" %s %d", nameProfile, &cod);
      i0 = search(nameProfile);

      for (i=0; i<cod; i++) {

	scanf(" %s", nameProfile);
	i1 = search(nameProfile);

	friends[i1].edgPessoa[friends[i1].cod++] = i0;
	ge[i0]++;

      }
    }

    n0 = 0;
    for (i=0; i<n; i++)
      if (ge[i]==0)
	gz[n0++] = i;

    n1 = 0;
    while (n0) {
      i = gz[--n0];
      out[n1++] = i;

      for (j=0; j<friends[i].cod; j++)
	if ((--ge[friends[i].edgPessoa[j]])==0)
	  gz[n0++] = friends[i].edgPessoa[j];
    }

    printf("Teste %d\n", aux++);
    if (n1 < n)
      printf("impossivel\n\n");
    else {
      printf("%s", friends[out[0]].nameProfile);
      for (i=1; i<n1; i++)
	printf(" %s", friends[out[i]].nameProfile);
      printf("\n\n");
    }
  }

  return 0;
}
