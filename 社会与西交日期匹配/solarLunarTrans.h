#ifndef SOLARLUNARTRANS_H
#define SOLARLUNARTRANS_H
typedef struct {
    int year;
    int month;
    int day;
    int reserved;
} Mydate;

Mydate toSolar(Mydate lunar);
Mydate toLunar(Mydate solar);

#endif