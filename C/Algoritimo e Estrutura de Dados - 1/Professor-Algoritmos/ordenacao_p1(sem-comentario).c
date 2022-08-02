#include <stdio.h>

void selectsort(int v[], int n)
{
	int i, j, p, aux;

	for (i = n - 1; i >= 1; i--)
	{
		p = i;

		for (j = 0; j < i; j++)
			if (v[j] > v[p])
				p = j;

		aux = v[i];
		v[i] = v[p];
		v[p] = aux;
	}
}

void selectsort2(int v[], int n)
{
	int i, j, p, aux;

	for (i = 0; i < n - 1; i++)
	{
		p = i;

		for (j = i + 1; j < n; j++)
		{
			if (v[j] < v[p])
			{
				p = j;
			}
		}
		if (p != i)
		{
			aux = v[i];
			v[i] = v[p];
			v[p] = aux;
		}
	}
}

static void gerarHeap(int v[], int n)
{
	int esq = n / 2;

	while (esq >= 0)
	{
		refazer(v, esq, n - 1);
		esq--;
	}
}

static void refazer(int v[], int esq, int dir)
{
	int j = (esq + 1) * 2 - 1, x = v[esq];

	while (j <= dir)
	{
		if ((j < dir) && (v[j] < v[j + 1]))
			j++;
		if (x > v[j])
			break;

		v[esq] = v[j];
		esq = j;
		j = (esq + 1) * 2 - 1;
	}

	v[esq] = x;
}

void heapsort(int v[], int n)
{
	int x, dir = n - 1;

	gerarHeap(v, n);

	while (dir > 0)
	{
		x = v[0];
		v[0] = v[dir];
		v[dir] = x;
		dir--;

		refazer(v, 0, dir);
	}
}