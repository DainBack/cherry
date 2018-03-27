#include <stdio.h>
void input_scores_file(FILE* infile, float score[], int n) {
	int c;
	for (c = 0; c<n; c++) {
		fscanf_s(infile, "%f\n", &score[c]);
	}
}

void save_result_file(FILE *outfile, float max, float min, float sum, float mean) {

	fprintf(outfile, "최고점수: %f\n", max);
	fprintf(outfile, "최저점수: %f\n", min);
	fprintf(outfile, "합계점수: %f\n", sum);
	fprintf(outfile, "평균점수: %f\n", mean);
}

float max_score(float score[], int n)
{
	// rotation
	int temp;
	if (n == 1)return score[n - 1];
	temp = max_score(score, n - 1);
	return(score[n - 1]>temp) ? score[n - 1] : temp;
	/*	int c=0;
	float max=0;
	c++;
	if (c==5) return max;
	if (max<score[c]) max = score[c];
	max_score(score,n);*/
}



float min_score(float score[], int n)
{
	// rotation
	int temp;
	if (n == 1)return score[n - 1];
	temp = min_score(score, n - 1);
	return(score[n - 1]<temp) ? score[n - 1] : temp;
	/*int c = 0;
	float min = 100;
	c++;
	if (c == 5) return min;
	if (min>score[c]) min = score[c];*/
}



float sum_scores(float score[], int n)
{
	// rotation
	int temp;
	if (n == 1)return score[n - 1];
	temp = sum_scores(score, n - 1);
	return temp + score[n - 1];
	/*int c=0;
	float sum=0;
	c++;
	if (c==5) return sum;
	sum += score[c];*/
}

void print_result(float max, float min, float sum, float mean)
{
	printf("**************************\n");
	printf("maximum : %f\n", max);
	printf("minimum : %f\n", min);
	printf("sum : %f\n", sum);
	printf("average : %f\n", mean);
	printf("**************************\n");
}

void main() {
	int n = 0;
	float max = 0, min = 100, sum = 0, mean = 0;
	float score[30];
	FILE *infile, *outfile;


	infile = fopen("score.txt", "r");
	if (infile == NULL)
	{
		printf("Error : Can not Open File!!!\n\n");
		return;
	}

	printf("Student Number? ");
	scanf("%d", &n);
	input_scores_file(infile, score, n);

	/*int c;
	for (c = 0; c<n; c++) {
		printf("%f", &score[c]);
	}
	*/
	fclose(infile);

	max = max_score(score, n);
	min = min_score(score, n);
	sum = sum_scores(score, n);
	mean = sum / (float)n;
	print_result(max, min, sum, mean);

	outfile = fopen("result.txt", "w");
	if (outfile == NULL)
	{
		printf("Error! Can not open File!!!\n\n");
		return;
	}
	save_result_file(outfile, max, min, sum, mean);
	fclose(outfile);
}

