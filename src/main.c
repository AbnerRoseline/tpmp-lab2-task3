#include <stdio.h>
#include "../include/train.h"

void demonstrate_prime_numbers_task() {
    printf("========== ЗАДАЧА 1: ТРЕХЗНАЧНЫЕ ПРОСТЫЕ ЧИСЛА ==========\n");
    int count = 0;
    for (int i = 100; i < 1000; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
            if (count % 15 == 0) {
                printf("\n");
            }
        }
    }
    printf("\n\nНайдено %d трехзначных простых чисел.\n", count);
    printf("=========================================================\n\n");
}

void demonstrate_train_task() {
    printf("========== ЗАДАЧА 2: СТРУКТУРА TRAIN ==========\n");
    TRAIN trains[MAX_TRAINS];
    int size = 0;

    populate_trains_data(trains, &size);
    printf("Были загружены данные о %d поездах.\n", size);

    print_long_trip_trains(trains, size);

    int total_coupe_passengers = get_total_passengers_in_coupe(trains, size);
    printf("\n--- Суммарное количество пассажиров в купейных вагонах ---\n");
    printf("Общее количество: %d пассажиров.\n", total_coupe_passengers);

    print_trains_to_grodno(trains, size);

    TRAIN max_car_train = find_train_with_max_cars(trains, size);
    printf("\n--- Поезд с максимальным количеством вагонов ---\n");
    print_train_info(&max_car_train);
    
    printf("================================================\n");
}

int main() {
    demonstrate_prime_numbers_task();
    demonstrate_train_task();
    return 0;
}
