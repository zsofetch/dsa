/*
================================================================================
REAL-LIFE PROBLEM: WEEKLY TASK TRACKER
================================================================================

SCENARIO: Student Daily Task Management
You're a student who needs to track which days of the week you completed
certain tasks. Each day is represented by a number:

Days of the week:
0 = Monday
1 = Tuesday  
2 = Wednesday
3 = Thursday
4 = Friday
5 = Saturday
6 = Sunday
7 = (ambot it needs to be 8 bits so lets js say this is an extra day for special events or sum shit)

Tasks to track:
- Workout
- Study
- Class
- Scheds with Friends
- Special Days
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// ============================================================================
// VARIATION 1: BITMASK APPROACH
// ============================================================================
// This variation is for tracking many schedules of students
// Each student's schedule fits in just 1 byte

typedef unsigned char Schedule_V1;

const char* day_names[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun", "Extra"};

void init_sched_v1 (Schedule_V1 *schedule) {
    *schedule = 0; //empty pa ang sched
}

//this is the insert function
void mark_day_v1(Schedule_V1 *schedule, int day) {
    if (day < 0 || day > 7) {
        printf("Invalid day dumdum!\n");
        return;
    }

    //dko sure if sakto ni still need to debug
    unsigned char mask = 1 << day;
    *schedule |= mask; //turn on the bit for that day
}

//this is the delete function
void unmark_day_v1(Schedule_V1 *schedule, int day) {
    if (day < 0 || day > 7) {
        printf("Invalid day dumdum!\n");
        return;
    }
    
    //dko sure if sakto ni still need to debug
    //naay shorter syntax for this block of code which is - *schedule &= ~(1 << day);
    unsigned char mask = 1 << day;
    mask = ~mask;
    *schedule &= mask;
}

//this is the find function
//it checks if the activity is scheduled on that day
bool is_scheduled_v1(Schedule_V1 schedule, int day) {
    if (day < 0 || day > 7) {
        return false;
    }

    //to debug pasd ni dko sure if mag make ug mask but i just followed sir edwin's guide
    unsigned char mask = 1 << day;
    return (schedule & mask) != 0;
}

//this is the intersection function so nangita tas days that are similarly scheduled in both scheds
Schedule_V1 common_days_v1(Schedule_V1 sched1, Schedule_V1 sched2) {
    return sched1 & sched2;
}

//this is the union function so nangita tas days that are schedules in EITHER of the sched
Schedule_V1 all_busy_days_v1(Schedule_V1 sched1, Schedule_V2 sched2) {
    return sched1 | sched2;
}

//this is the difference function so nangita ratas days that are in sched 1 but NOT in sched2
Schedule_V1 only_in_first_sched_v1(Schedule_V1 sched1, Schedule_V1 sched2) {
    return sched1 & (~sched2);
}

//to debug pani
void display_sched_v1(const char* label, Schedule_V1 schedule) {
    printf("%s: ", label);
    bool first = true; 

    for (int i = 0; i <= 7; i++) {
        if(is_scheduled_v1(schedule, i)) {
            if (!first) printf(", ");
            printf("%d", i);
            first = false;
        }
    }
    if (first)
    printf("No days scheduled!\n");
}

// ============================================================================
// VARIATION 2: BIT FIELDS APPROACH
// ============================================================================

typedef struct {
    unsigned int days : 8;
} Schedule_V2;


void init_sched_v2(Schedule_V2 *schedule) {
    schedule->days = 0;
}

//to be debugged
void mark_day_v2(Schedule_V2 *schedule, int day) {
    if (day < 0 || day > 7) return;
    schedule->days != (1 << day);
}

//to be debugged
void unmark_day_v2(Schedule_V2 *schedule, int day) {
    if (day < 0 || day > 7) return;
    
    /*unsigned int mask = 1 << day;
    mask = ~mask;
    schedule->days &= mask;*/

    schedule->days &= ~(1 << day);
}

//this is the find function
//to be debugged pud
bool is_scheduled_v2(Schedule_V2 schedule, int day) {
    if (day < 0 || day > 7) {
        return false;
    }
    return (schedule.days & (1 << day)) != 0;

}

//intersection
Schedule_V2 common_days_v2(Schedule_V2 sched1, Schedule_V2 sched2) {
    Schedule_V2 sched3;

    sched3.days = sched1.days & sched2.days;

    return sched3;

}

//union
Schedule_V2 all_busy_days_v2(Schedule_V2 sched1, Schedule_V2 sched2) {
    Schdeule_V2 sched3;

    sched3.days = sched1.days | sched2.days;

    return sched3;
}

//difference
Schedule_V2 only_in_first_sched_v2(Schedule_V2 sched1, Schedule_V2 sched2) {
    Schedule_V2 sched3;

    sched3.days = sched1.days & ~(sched2.days);

    return sched3;
}

void display_schedule_v2(const char* label, Schedule_v2 schedule) {
    printf("%s: ", label);
    bool first = true;
    for (int i = 0; i <= 7; i++) {
    if(is_scheduled_v2(schedule, i)) {
        if (!first) printf(", ");
        // printf("%s", day_names[i]); --- lahi ang printing format for var 2
        printf("%s" i);
        first = false;
    }
}
    if (first) 
    printf("No days scheduled!\n");
}

// ============================================================================
// VARIATION 3: BOOLEAN ARRAY APPROACH 
// ============================================================================


typedef bool Schedule_V3[8];  // Array of 8 boolean values
void init_sched_v3(Schedule_V3 schedule) {
    for (int i = 0; i < 8; i++) {
        schedule[i] = false;
    }
}

void mark_day_v3(Schedule_V3 schedule, int day) {
    if (day < 0 || day > 7) {
        printf("Invalid day silly!");
        return;
    }

    schedule[day] = true;
}

void unmark_day_v3(Schedule_V3 schedule, int day) {
    if (day < 0 || day > 7) return;

    schedule[day] = false;
}

void is_scheduled_v3(Schedule_V3 schedule, int day) {
    if (day < 0 || day > 7) return;

    return schedule[day];
}

//intersection
void common_days_v3(Schedule_V3 sched1, Schedule_V3 sched2, Schedule_V3 sched3) {
    for (int i = 0; i < 8; i++) {
        sched3[i] = sched1[i] && sched2[i];
    }
}

//union
void all_busy_days_v3(Schedule_V3 sched1, Schedule_V3 sched2, Schedule_V3 sched3) {
    for (int i = 0; i < 8; i++) {
        sched3[i] = sched1[i] || sched2[i];
    }
}

//difference
void only_in_first_v3(Schedule_V3 sched1, Schedule_V3 sched2, Schedule_V3 sched3) {
    for (int i = 0; i < 8; i++) {
        sched3[i] = sched1[i] && !sched2[i];
    }
}

void display_schedule_v3(const char* label, Schedule_V3 schedule) {
    printf("%s: ", label);
    bool first = true;
    for (int i = 0; i < 8; i++) {
        if (schedule[i]) {
            if (!first) printf(", ");
            printf("%s", day_names[i]);
            first = false;
        }
    }
    if (first) printf("No days scheduled");
    printf("\n");
}

int main() {
    printf("================================================================================\n");
    printf("                    WEEKLY TASK TRACKER - STUDENT SCENARIO\n");
    printf("================================================================================\n\n");
    
    //scenario: three students want to coordinate their scheds
    //menu - based scenario
    
    printf("Zsof, Shane, and Thea - want to:\n");
    printf("1. Track when they workout\n");
    printf("2. Find common vacant days to study together\n");
    printf("3. Find days when the apartment is free\n\n");
    

    //=== using variation 1 ===
    printf("===== VARIATION 1: BITMASK APPROACH =====\n");
    
    // initializing schedules
    Schedule_V1 zsof_workout, shane_workout, thea_workout;
    init_sched_v1(&zsof_workout);
    init_sched_v1(&shane_workout);
    init_sched_v1(&thea_workout);
    
    // zsof works out on Mon, Wed, Fri (days 0, 2, 4)
    printf("Zsof's Workout Schedule:\n");
    mark_day_v1(&zsof_workout, 0);  // Monday
    mark_day_v1(&zsof_workout, 2);  // Wednesday
    mark_day_v1(&zsof_workout, 4);  // Friday
    display_schedule_v1("Zsof works out", zsof_workout);
    
    // shane works out on Tue, Thu, Sat (days 1, 3, 5)
    printf("\nShane's Workout Schedule:\n");
    mark_day_v1(&shane_workout, 1);  // Tuesday
    mark_day_v1(&shane_workout, 3);  // Thursday
    mark_day_v1(&shane_workout, 5);  // Saturday
    display_schedule_v1("Shane works out", shane_workout);
    
    // thea works out exercises on Wed, Fri, Sun (days 2, 4, 6)
    printf("\nThea's Workout Schedule:\n");
    mark_day_v1(&thea_workout, 2);  // Wednesday
    mark_day_v1(&thea_workout, 4);  // Friday
    mark_day_v1(&thea_workout, 6);  // Sunday
    display_schedule_v1("Thea works out", thea_workout);
    
    // find common days when Zsof and Thea both exercise
    printf("\n--- Analysis ---\n");
    Schedule_V1 zsof_thea_common = common_days_v1(zsof_workout, thea_workout);
    display_schedule_v1("Zsof and Thea both exercise", zsof_thea_common);
    
    // Find all days when someone is exercising
    Schedule_V1 all_busy = all_busy_days_v1(alice_exercise, bob_exercise);
    all_busy = all_busy_days_v1(all_busy, carol_exercise);
    display_schedule_v1("At least one person exercising", all_busy);
    
    // Find days when Alice exercises but Bob doesn't
    Schedule_V1 alice_not_bob = only_in_first_v1(alice_exercise, bob_exercise);
    display_schedule_v1("Alice exercises (Bob doesn't)", alice_not_bob);
    
    printf("\nMemory used: %lu bytes per person\n", sizeof(Schedule_V1));
    
    // ========================================================================
    // USING VARIATION 2: BIT FIELDS (Clean code)
    // ========================================================================
    printf("\n\n===== VARIATION 2: BIT FIELDS APPROACH =====\n");
    printf("(Good balance of efficiency and readability)\n\n");
    
    // Track class attendance
    Schedule_V2 alice_classes, bob_classes;
    init_v2(&alice_classes);
    init_v2(&bob_classes);
    
    // Alice has classes Mon-Fri (days 0-4)
    printf("Alice's Class Schedule:\n");
    for (int i = 0; i <= 4; i++) {
        mark_day_v2(&alice_classes, i);
    }
    display_schedule_v2("Alice has classes", alice_classes);
    
    // Bob has classes Tue, Thu, Fri (days 1, 3, 4)
    printf("\nBob's Class Schedule:\n");
    mark_day_v2(&bob_classes, 1);
    mark_day_v2(&bob_classes, 3);
    mark_day_v2(&bob_classes, 4);
    display_schedule_v2("Bob has classes", bob_classes);
    
    // Find days when both have classes (can study together after)
    printf("\n--- Analysis ---\n");
    Schedule_V2 study_together = common_days_v2(alice_classes, bob_classes);
    display_schedule_v2("Can study together after class", study_together);
    
    // Find days when only Alice has class
    Schedule_V2 alice_only = only_in_first_v2(alice_classes, bob_classes);
    display_schedule_v2("Only Alice has class", alice_only);
    
    printf("\nMemory used: %lu bytes per person\n", sizeof(Schedule_V2));
    
    // ========================================================================
    // USING VARIATION 3: BOOLEAN ARRAY (Most intuitive)
    // ========================================================================
    printf("\n\n===== VARIATION 3: BOOLEAN ARRAY APPROACH =====\n");
    printf("(Most beginner-friendly and readable)\n\n");
    
    // Track study sessions
    Schedule_V3 alice_study, bob_study, carol_study, group_study;
    init_v3(alice_study);
    init_v3(bob_study);
    init_v3(carol_study);
    
    // Alice studies on Mon, Tue, Wed, Thu (days 0, 1, 2, 3)
    printf("Alice's Study Schedule:\n");
    mark_day_v3(alice_study, 0);  // Monday
    mark_day_v3(alice_study, 1);  // Tuesday
    mark_day_v3(alice_study, 2);  // Wednesday
    mark_day_v3(alice_study, 3);  // Thursday
    display_schedule_v3("Alice studies", alice_study);
    
    // Bob studies on Tue, Wed, Fri (days 1, 2, 4)
    printf("\nBob's Study Schedule:\n");
    mark_day_v3(bob_study, 1);  // Tuesday
    mark_day_v3(bob_study, 2);  // Wednesday
    mark_day_v3(bob_study, 4);  // Friday
    display_schedule_v3("Bob studies", bob_study);
    
    // Carol studies on Wed, Thu, Sat (days 2, 3, 5)
    printf("\nCarol's Study Schedule:\n");
    mark_day_v3(carol_study, 2);  // Wednesday
    mark_day_v3(carol_study, 3);  // Thursday
    mark_day_v3(carol_study, 5);  // Saturday
    display_schedule_v3("Carol studies", carol_study);
    
    // Find days when all three can study together
    printf("\n--- Analysis ---\n");
    common_days_v3(alice_study, bob_study, group_study);
    common_days_v3(group_study, carol_study, group_study);
    display_schedule_v3("All three can study together", group_study);
    
    // Find days when at least one person is studying
    all_busy_days_v3(alice_study, bob_study, group_study);
    all_busy_days_v3(group_study, carol_study, group_study);
    display_schedule_v3("At least one person studying", group_study);
    
    // Find days when Alice studies but Carol doesn't (can ask Carol for help)
    only_in_first_v3(alice_study, carol_study, group_study);
    display_schedule_v3("Alice free (Carol studying)", group_study);
    
    printf("\nMemory used: %lu bytes per person\n", sizeof(Schedule_V3));
    
    // ========================================================================
    // PRACTICAL USE CASE: Finding Best Meeting Day
    // ========================================================================
    printf("\n\n===== PRACTICAL APPLICATION: FIND BEST MEETING DAY =====\n");
    printf("Problem: When can all three roommates meet for apartment cleaning?\n\n");
    
    // Using Variation 1 for this (most efficient)
    Schedule_V1 alice_free, bob_free, carol_free;
    
    // Alice is free on weekends (Sat=5, Sun=6)
    init_v1(&alice_free);
    mark_day_v1(&alice_free, 5);
    mark_day_v1(&alice_free, 6);
    display_schedule_v1("Alice free", alice_free);
    
    // Bob is free on Wed, Sat, Sun (2, 5, 6)
    init_v1(&bob_free);
    mark_day_v1(&bob_free, 2);
    mark_day_v1(&bob_free, 5);
    mark_day_v1(&bob_free, 6);
    display_schedule_v1("Bob free", bob_free);
    
    // Carol is free on Sat, Sun (5, 6)
    init_v1(&carol_free);
    mark_day_v1(&carol_free, 5);
    mark_day_v1(&carol_free, 6);
    display_schedule_v1("Carol free", carol_free);
    
    // Find common free days
    Schedule_V1 common_free = common_days_v1(alice_free, bob_free);
    common_free = common_days_v1(common_free, carol_free);
    
    printf("\n*** RESULT: ");
    display_schedule_v1("Best days to meet", common_free);
    
    if (common_free != 0) {
        printf("✓ They should schedule apartment cleaning on these days!\n");
    } else {
        printf("✗ No common free days - they need to negotiate!\n");
    }
    
    // ========================================================================
    // COMPARISON SUMMARY
    // ========================================================================
    printf("\n\n================================================================================\n");
    printf("                              COMPARISON SUMMARY\n");
    printf("================================================================================\n");
    printf("Variation 1 (Bitmask):      %lu byte  - Best for: Large-scale tracking\n", sizeof(Schedule_V1));
    printf("Variation 2 (Bit Fields):   %lu byte  - Best for: Production code\n", sizeof(Schedule_V2));
    printf("Variation 3 (Bool Array):   %lu bytes - Best for: Learning/Readability\n", sizeof(Schedule_V3));
    printf("\nFor tracking 1000 students:\n");
    printf("- Variation 1: %lu bytes (%.2f KB)\n", 1000 * sizeof(Schedule_V1), 1000 * sizeof(Schedule_V1) / 1024.0);
    printf("- Variation 2: %lu bytes (%.2f KB)\n", 1000 * sizeof(Schedule_V2), 1000 * sizeof(Schedule_V2) / 1024.0);
    printf("- Variation 3: %lu bytes (%.2f KB)\n", 1000 * sizeof(Schedule_V3), 1000 * sizeof(Schedule_V3) / 1024.0);
    printf("================================================================================\n");
    
    return 0;
}