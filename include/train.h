#ifndef TRAIN_H
#define TRAIN_H

#define MAX_TRAINS 12
#define DEST_SIZE 100
#define TIME_SIZE 6
#define TYPE_SIZE 50

typedef struct {
    int train_number;
    char destination[DEST_SIZE];
    char departure_time[TIME_SIZE];
    char arrival_time[TIME_SIZE];
    float distance;
    int car_count;
    char car_type[TYPE_SIZE];
    int passenger_count;
} TRAIN;

void populate_trains_data(TRAIN trains[], int* size);
void print_long_trip_trains(const TRAIN trains[], int size);
int get_total_passengers_in_coupe(const TRAIN trains[], int size);
void print_trains_to_grodno(const TRAIN trains[], int size);
TRAIN find_train_with_max_cars(const TRAIN trains[], int size);
void print_train_info(const TRAIN* train);
int is_prime(int n);

#endif
