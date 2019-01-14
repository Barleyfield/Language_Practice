int main(void)
{
	int diff = 'a' - 'A';
	char word;
	scanf("%c", &word);

	word = word - diff;
	printf("%d\n", diff);

	printf("%c", word);
	return 0;
}
