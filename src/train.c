#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/train.h"

#Добавлен комментарий для шага 19
void print_train_info(const TRAIN* train) {
    if (train == NULL) return;
    printf("----------------------------------------\n");
    printf("Поезд №: %d\n", train->train_number);
    printf("  Направление: %s\n", train->destination);
    printf("  Отправление: %s\n", train->departure_time);
    printf("  Прибытие: %s\n", train->arrival_time);
    printf("  Расстояние: %.2f км\n", train->distance);
    printf("  Кол-во вагонов: %d\n", train->car_count);
    printf("  Тип вагонов: %s\n", train->car_type);
    printf("  Пассажиров в вагоне: %d\n", train->passenger_count);
    printf("----------------------------------------\n");
}

void populate_trains_data(TRAIN trains[], int* size) {
    *size = 5;
    trains[0] = (TRAIN){101, "Гродно", "08:00", "14:30", 350.5, 10, "купе", 36};
    trains[1] = (TRAIN){205, "Брест", "22:15", "06:45", 400.0, 15, "плацкарт", 54};
    trains[2] = (TRAIN){107, "Гродно", "11:00", "17:20", 350.5, 12, "плацкарт", 54};
    trains[3] = (TRAIN){301, "Витебск", "15:00", "21:00", 300.0, 18, "сидячий", 72};
    trains[4] = (TRAIN){404, "Гомель", "09:30", "15:00", 320.0, 10, "купе", 30};
}

void print_long_trip_trains(const TRAIN trains[], int size) {
    printf("\n--- Поезда в пути более суток ---\n");
    int found = 0;
    for (int i = 0; i < size; ++i) {
        if (strcmp(trains[i].arrival_time, trains[i].departure_time) < 0) {
            print_train_info(&trains[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Поездов, находящихся в пути более суток, не найдено.\n");
    }
}

int get_total_passengers_in_coupe(const TRAIN trains[], int size) {
    int total_passengers = 0;
    for (int i = 0; i < size; ++i) {
        if (strcmp(trains[i].car_type, "купе") == 0) {
            total_passengers += trains[i].passenger_count * trains[i].car_count;
        }
    }
    return total_passengers;
}

void print_trains_to_grodno(const TRAIN trains[], int size) {
    printf("\n--- Поезда, следующие в Гродно ---\n");
    int found = 0;
    for (int i = 0; i < size; ++i) {
        if (strcmp(trains[i].destination, "Гродно") == 0) {
            print_train_info(&trains[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Поездов, следующих в Гродно, не найдено.\n");
    }
}

TRAIN find_train_with_max_cars(const TRAIN trains[], int size) {
    if (size == 0) {
        return (TRAIN){0, "", "", "", 0.0, 0, "", 0};
    }
    
    TRAIN max_car_train = trains[0];
    for (int i = 1; i < size; ++i) {
        if (trains[i].car_count > max_car_train.car_count) {
            max_car_train = trains[i];
        }
    }
    return max_car_train;
}

int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
