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
7 = (Extra day for special events)

Tasks to track:
- Which days did I exercise?
- Which days did I study?
- Which days did I attend classes?
- Compare schedules with friends
- Find common free days

This is PERFECT for bit vector sets because:
- Limited set of elements (0-7 days)
- Only need to know presence/absence (yes/no)
- Need to compare sets (intersection, union, difference)
- Memory efficient when tracking multiple weeks
================================================================================
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// ============================================================================
// VARIATION 1: BITMASK APPROACH (Most Memory Efficient)
// ============================================================================
// Use this when: Tracking many students' schedules or multiple weeks

// Each student's schedule fits in just 1 byte!
typedef unsigned char Schedule_V1;

// Day names for display
const char* day_names[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun", "Extra"};

void init_v1(Schedule_V1 *schedule) {
    *schedule = 0;  // No activities scheduled initially
}

void mark_day_v1(Schedule_V1 *schedule, int day) {
    // Mark a day as having the activity
    if (day < 0 || day > 7) {
        printf("Invalid day!\n");
        return;
    }
    *schedule |= (1 << day);  // Turn on the bit for that day
}

void unmark_day_v1(Schedule_V1 *schedule, int day) {
    // Remove a day from the schedule
    if (day < 0 || day > 7) return;
    *schedule &= ~(1 << day);  // Turn off the bit for that day
}

bool is_scheduled_v1(Schedule_V1 schedule, int day) {
    // Check if activity is scheduled on this day
    if (day < 0 || day > 7) return false;
    return (schedule & (1 << day)) != 0;
}

Schedule_V1 common_days_v1(Schedule_V1 schedule1, Schedule_V1 schedule2) {
    // Find days that are scheduled in BOTH schedules (intersection)
    return schedule1 & schedule2;
}

Schedule_V1 all_busy_days_v1(Schedule_V1 schedule1, Schedule_V1 schedule2) {
    // Find days that are scheduled in EITHER schedule (union)
    return schedule1 | schedule2;
}

Schedule_V1 only_in_first_v1(Schedule_V1 schedule1, Schedule_V1 schedule2) {
    // Find days scheduled in first but NOT in second (difference)
    return schedule1 & (~schedule2);
}

void display_schedule_v1(const char* label, Schedule_V1 schedule) {
    printf("%s: ", label);
    bool first = true;
    for (int i = 0; i <= 7; i++) {
        if (is_scheduled_v1(schedule, i)) {
            if (!first) printf(", ");
            printf("%s", day_names[i]);
            first = false;
        }
    }
    if (first) printf("No days scheduled");
    printf("\n");
}

// ============================================================================
// VARIATION 2: BIT FIELDS APPROACH (Clean and Efficient)
// ============================================================================
// Use this when: You want readable code with good efficiency

typedef struct {
    unsigned int days : 8;  // 8 bits for 8 days
} Schedule_V2;

void init_v2(Schedule_V2 *schedule) {
    schedule->days = 0;
}

void mark_day_v2(Schedule_V2 *schedule, int day) {
    if (day < 0 || day > 7) {
        printf("Invalid day!\n");
        return;
    }
    schedule->days |= (1 << day);
}

void unmark_day_v2(Schedule_V2 *schedule, int day) {
    if (day < 0 || day > 7) return;
    schedule->days &= ~(1 << day);
}

bool is_scheduled_v2(Schedule_V2 schedule, int day) {
    if (day < 0 || day > 7) return false;
    return (schedule.days & (1 << day)) != 0;
}

Schedule_V2 common_days_v2(Schedule_V2 s1, Schedule_V2 s2) {
    Schedule_V2 result;
    result.days = s1.days & s2.days;
    return result;
}

Schedule_V2 all_busy_days_v2(Schedule_V2 s1, Schedule_V2 s2) {
    Schedule_V2 result;
    result.days = s1.days | s2.days;
    return result;
}

Schedule_V2 only_in_first_v2(Schedule_V2 s1, Schedule_V2 s2) {
    Schedule_V2 result;
    result.days = s1.days & (~s2.days);
    return result;
}

void display_schedule_v2(const char* label, Schedule_V2 schedule) {
    printf("%s: ", label);
    bool first = true;
    for (int i = 0; i <= 7; i++) {
        if (is_scheduled_v2(schedule, i)) {
            if (!first) printf(", ");
            printf("%s", day_names[i]);
            first = false;
        }
    }
    if (first) printf("No days scheduled");
    printf("\n");
}

// ============================================================================
// VARIATION 3: BOOLEAN ARRAY APPROACH (Most Intuitive)
// ============================================================================
// Use this when: Code clarity is priority, or for beginners

typedef bool Schedule_V3[8];  // Array of 8 boolean values

void init_v3(Schedule_V3 schedule) {
    for (int i = 0; i < 8; i++) {
        schedule[i] = false;  // No days scheduled
    }
}

void mark_day_v3(Schedule_V3 schedule, int day) {
    if (day < 0 || day > 7) {
        printf("Invalid day!\n");
        return;
    }
    schedule[day] = true;  // Very intuitive!
}

void unmark_day_v3(Schedule_V3 schedule, int day) {
    if (day < 0 || day > 7) return;
    schedule[day] = false;
}

bool is_scheduled_v3(Schedule_V3 schedule, int day) {
    if (day < 0 || day > 7) return false;
    return schedule[day];  // Direct array access
}

void common_days_v3(Schedule_V3 s1, Schedule_V3 s2, Schedule_V3 result) {
    for (int i = 0; i < 8; i++) {
        result[i] = s1[i] && s2[i];  // Both must be true
    }
}

void all_busy_days_v3(Schedule_V3 s1, Schedule_V3 s2, Schedule_V3 result) {
    for (int i = 0; i < 8; i++) {
        result[i] = s1[i] || s2[i];  // Either can be true
    }
}

void only_in_first_v3(Schedule_V3 s1, Schedule_V3 s2, Schedule_V3 result) {
    for (int i = 0; i < 8; i++) {
        result[i] = s1[i] && !s2[i];  // In first but not in second
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

// ============================================================================
// MAIN PROGRAM: REALISTIC SCENARIO
// ============================================================================

int main() {
    printf("================================================================================\n");
    printf("                    WEEKLY TASK TRACKER - STUDENT SCENARIO\n");
    printf("================================================================================\n\n");
    
    // SCENARIO: Three roommates want to coordinate their schedules
    
    printf("SCENARIO: Three roommates - Alice, Bob, and Carol - want to:\n");
    printf("1. Track when they exercise\n");
    printf("2. Find common days to study together\n");
    printf("3. Find days when the apartment is free\n\n");
    
    // ========================================================================
    // USING VARIATION 1: BITMASK (Most compact)
    // ========================================================================
    printf("===== VARIATION 1: BITMASK APPROACH =====\n");
    printf("(Most memory efficient - only 1 byte per person!)\n\n");
    
    // Initialize schedules
    Schedule_V1 alice_exercise, bob_exercise, carol_exercise;
    init_v1(&alice_exercise);
    init_v1(&bob_exercise);
    init_v1(&carol_exercise);
    
    // Alice exercises on Mon, Wed, Fri (days 0, 2, 4)
    printf("Alice's Exercise Schedule:\n");
    mark_day_v1(&alice_exercise, 0);  // Monday
    mark_day_v1(&alice_exercise, 2);  // Wednesday
    mark_day_v1(&alice_exercise, 4);  // Friday
    display_schedule_v1("Alice exercises", alice_exercise);
    
    // Bob exercises on Tue, Thu, Sat (days 1, 3, 5)
    printf("\nBob's Exercise Schedule:\n");
    mark_day_v1(&bob_exercise, 1);  // Tuesday
    mark_day_v1(&bob_exercise, 3);  // Thursday
    mark_day_v1(&bob_exercise, 5);  // Saturday
    display_schedule_v1("Bob exercises", bob_exercise);
    
    // Carol exercises on Wed, Fri, Sun (days 2, 4, 6)
    printf("\nCarol's Exercise Schedule:\n");
    mark_day_v1(&carol_exercise, 2);  // Wednesday
    mark_day_v1(&carol_exercise, 4);  // Friday
    mark_day_v1(&carol_exercise, 6);  // Sunday
    display_schedule_v1("Carol exercises", carol_exercise);
    
    // Find common days when Alice and Carol both exercise
    printf("\n--- Analysis ---\n");
    Schedule_V1 alice_carol_common = common_days_v1(alice_exercise, carol_exercise);
    display_schedule_v1("Alice & Carol both exercise", alice_carol_common);
    
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