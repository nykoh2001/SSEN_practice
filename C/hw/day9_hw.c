#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE(x) (sizeof(x) / sizeof((x)[0]))

/*
* TODO: 메모리 한 번만 할당하도록 최적화, 대규모 데이터 처리할 때 고려
* 메모리 공간을 갖는 변수를 반복문 안의 변수로 선언 시 매번 재할당 -> 고려해서 최적화
*/
// 포인터 배열도 동적할당, 배열의 멤버도 동적할당 받는 코드 작성
#if 1
char *colors[] = {"white",  "black", "blue",  "red",
                  "orange", "pink",  "green", "gray"};

typedef struct _profile {
    int age;
    char **color;
    char *name; // 이름이 나중에(사용중) 변경 가능하다고 가정함
    
    int color_count;
} profile;

typedef struct _student {
    int num;
    double grade;
    profile prof;
} student;

int get_color_idx(char *color) {
    for (int i = 0; i < SIZE(colors); i++) {
      if (strcmp(colors[i], color) == 0)
        return i;
    }
    return -1;
}

void free_mem(student **p, int n) {
    if (p == NULL || *p == NULL)
      return;
    for (int i = 0; i < n; i++) {
      free((*p)[i].prof.color);
      free((*p)[i].prof.name);
    }
    free(*p);
    *p = NULL;
}

student* init_student(int n) {
    if (n <= 0)
      return NULL;
    student *stu = (student *)calloc(n, sizeof(student));
    if (stu == NULL)
      return NULL;

    for (int i = 0; i < n; ++i) {
      profile *prof = &stu[i].prof;
      scanf("%d %lf %d %d", &stu[i].num, &stu[i].grade, &prof->age, &prof->color_count);

      prof->color = (char **)malloc(sizeof(char *) * prof->color_count);
      if (prof->color == NULL) {
        free_mem(&stu, n);
        return NULL;
      }

      for (int j = 0; j < prof->color_count; j++) {
        char curr_color[21];
        scanf("%20s", curr_color);
        
        int color_idx = get_color_idx(curr_color);
        if (color_idx == -1) {
          free_mem(&stu, n);
          return NULL;
        }
        prof->color[j] = colors[color_idx];
      }

      char name_input[21];
      scanf("%20s", name_input);

      prof->name = (char *)malloc(strlen(name_input) + 1);
      if (prof->name == NULL) {
        free_mem(&stu, n);
        return NULL;
      }

      strcpy(prof->name, name_input);
    }
    return stu;
}

void print_student(student *p, int n) {
    for (int i = 0; i < n; i++) {
      profile *prof = &p[i].prof;
      printf("%d %.1lf %d", p[i].num, p[i].grade, prof->age);
      for (int j = 0; j < prof->color_count; j++)
        printf(" %s", prof->color[j]);
      printf(" %s\n", prof->name);
    }
}


int main(void) {
    student *stu = 0;
    int n;
    freopen("student3.txt", "r", stdin);
    scanf("%d", &n);

    stu = init_student(n);
    if (stu == NULL)
        return 12;
    
    print_student(stu, n);
    free_mem(&stu, n);
    return 0;
}
#endif
