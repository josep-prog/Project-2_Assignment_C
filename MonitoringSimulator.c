#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Device {
    char name[30];
    int type;
    union {
        float temperature;
        int pressure;
        float voltage;
    } reading;
};

void battery_monitor(struct Device *d) {
    printf("[%s] Battery: %.2f volts\n", d->name, d->reading.voltage);
}

void temperature_monitor(struct Device *d) {
    printf("[%s] Temp: %.2f°C\n", d->name, d->reading.temperature);
}

void pressure_monitor(struct Device *d) {
    printf("[%s] Pressure: %d psi\n", d->name, d->reading.pressure);
}

void demo_union(struct Device *d) {
    printf("\nDemonstrating Union for %s:\n", d->name);
    d->reading.temperature = 25.5;
    printf("After storing temp 25.5: temp=%.2f, pressure=%d, voltage=%.2f\n", 
           d->reading.temperature, d->reading.pressure, d->reading.voltage);
    d->reading.pressure = 99;
    printf("After storing pressure 99: temp=%.2f, pressure=%d (only last write is valid)\n", 
           d->reading.temperature, d->reading.pressure);
}

void process_device(struct Device *d, void (*callback)(struct Device*)) {
    callback(d);
}

int main() {
    srand(54321);
    int student_id = 54321;
    printf("Student ID: %d\n\n", student_id);
    
    struct Device *devices;
    int num_devices = 3;
    
    devices = (struct Device*)malloc(num_devices * sizeof(struct Device));
    
    strcpy(devices[0].name, "Battery Sensor");
    devices[0].type = 3;
    strcpy(devices[1].name, "Temperature Sensor");
    devices[1].type = 1;
    strcpy(devices[2].name, "Pressure Sensor");
    devices[2].type = 2;
    
    printf("Device array at: %p\n", (void*)devices);
    demo_union(&devices[0]);
    
    printf("\n=== Pointer Traversal Demo ===\n");
    for (struct Device *ptr = devices; ptr < devices + num_devices; ptr++) {
        printf("Device %ld: %s (type %d) at %p\n", 
               ptr - devices, ptr->name, ptr->type, (void*)ptr);
    }
    
    printf("\n=== Processing 10 Random Readings ===\n");
    for(int i = 0; i < 10; i++) {
        int idx = rand() % 3;
        struct Device *current = devices + idx;
        
        if(current->type == 1) {
            current->reading.temperature = 20.0 + (rand() % 200) / 10.0;
            process_device(current, temperature_monitor);
        }
        else if(current->type == 2) {
            current->reading.pressure = rand() % 100;
            process_device(current, pressure_monitor);
        }
        else if(current->type == 3) {
            current->reading.voltage = 3.0 + (rand() % 20) / 10.0;
            process_device(current, battery_monitor);
        }
    }
    
    free(devices);
    return 0;
}