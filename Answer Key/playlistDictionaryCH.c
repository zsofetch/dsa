//MAIN.C =====================
#include<stdio.h>
#include<string.h>
#include "cldi.h"

int main(){
	Song songBook[20]={	{"Someone Like You","Adele","Ballad"},
						{"Yellow Submarine","Beatles","Pop Rock"},
						{"Training Season","Dua Lipa","Pop"},
						{"Let's go back","Jungle","Dance"},
						{"Sway","Michael Buble","Jazz"},
						{"Love Story","Taylor Swift","Country Pop"},
						{"Where is my Husband?","Raye","Jazz"},
						{"Fly me to the moon","Frank Sinatra","Jazz"},
						{"Thinking Out Loud","Ed Sheeran","Ballad"},
						{"Back on 74","Jungle","Dance"},
						{"Mr. Brightside","The Killers","Pop Rock"},
						{"Kirari","Fuji Kaze","J-Pop"},
						{"This is What You Came For","Calvin Harris","Pop"},
						{"Rock with you","SEVENTEEN","K-Pop"},
						{"Symphony no. 8","Beethoven","Classical"},
						{"Defying Gravity","Wicked","Theater"},
						{"Alone","Marshmello","EDM"},
						{"Buwan","Juan Karlos","OPM"},
						{"NO PROBLEMZ","Jungle","Dance"},
						{"Doo Wop'","Lauryn Hill","R&B"}};

	int trav;
	Song temp={"Fly me to the moon","Frank Sinatra","Jazz"};
	Song check={"Everynight","Jungle","Dance"};
	Song delFirst={"Training Season","Dua Lipa","Pop"};
	VirtualHeap VH;

	initDict(&VH);

	for(trav=0;trav<20;trav++){
		insert(&VH,songBook[trav]);
	}

	displayDict(VH);
	printf("\n");

	printf("\nThe song \"%s\" %s in my playlist",check.songName,(search(VH,check))?"exists":"does not exist");
	printf("\nThe song \"%s\" %s in my playlist",temp.songName,(search(VH,temp))?"exists":"does not exist");

	printf("\n\nDeleting song %s",temp.songName);
	deleteMember(&VH,temp);
	printf("\nDeleting song %s",delFirst.songName);
	deleteMember(&VH,delFirst);
	printf("\n\nInserting song %s",check.songName);
	insert(&VH,check);

	printf("\n");
	displayDict(VH);

	return 0;

}

//CLDI.H =====================
#ifndef CLDI_H
#define CLDI_H

#define MAX 32

#include<stdio.h>
#include<string.h>


typedef char String[30];

typedef struct{
	String songName;
	String singer;
	String genre;
}Song;

typedef struct{
	Song elem;
	int next;
}Heapspace;

typedef struct{
	Heapspace H[MAX];
	int avail;
}VirtualHeap;


void initDict(VirtualHeap *VH);

void insert(VirtualHeap *VH,Song song);
void deleteMember(VirtualHeap *VH,Song song);
int search(VirtualHeap VH,Song song);

int hash(String genre);
void displayDict(VirtualHeap VH);

#endif // CLDI_H

//HELPER.C =====================
#include<stdio.h>
#include<string.h>
#include "cldi.h"


void initDict(VirtualHeap *VH)
{
	int i,Lim,Half;
	Lim=MAX-1;
	Half=MAX/2;
	for(i=0 ; i<Half ; i++){
		strcpy(VH->H[i].elem.genre,"Empty");
        VH->H[i].elem.songName[0] = '\0';
        VH->H[i].elem.singer[0] = '\0';
		VH->H[i].next=-1;
	}


	for(; i<Lim ; i++){
		VH->H[i].next=i+1;
	}

	VH->H[i].next=-1;
	VH->avail=16;
}


void displayDict(VirtualHeap VH){

	int trav,cntr,set,LIM;
	set=1;
	LIM=MAX/2;

	printf("Playlist of Janie Sabado");
	printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
	printf("\n  %3s   %30s   %-15s   %-13s","Ndx","Song Name","Singer","Genre");
	printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
	for(trav=0;trav<LIM;trav++){
		if(strcmp(VH.H[trav].elem.genre,"Empty")==0){
			printf("\n  %3d.  %30s - %-15s | %-13s",trav+1,"---","---","---");
			//printf("%5d",VH.H[trav].next);
		}else{
			printf("\n  %3d.  %30s - %-15s | %-13s",trav+1,VH.H[trav].elem.songName,VH.H[trav].elem.singer,VH.H[trav].elem.genre);
			//printf("%5d",VH.H[trav].next);
            cntr = VH.H[trav].next;
            while(cntr != -1){
                printf("\n        %30s - %-15s | %-13s",VH.H[cntr].elem.songName, VH.H[cntr].elem.singer, VH.H[cntr].elem.genre);
                //printf("%5d",VH.H[cntr].next);
				cntr = VH.H[cntr].next;
            }
		}

		printf("\n\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
	}

}

//CLDI.C =====================
#include<stdio.h>
#include<string.h>
#include "cldi.h"

String genreTable[16] = {
    "Ballad", "Pop Rock", "Pop", "R&B", "Rock", "Country Pop", "J-Pop", "K-Pop",
    "Classical", "Theater", "EDM", "OPM", "Reggae","Dance", "Jazz",  "Indie"
};

//Write your functions here...
int hash(String genre) {
    //compare the string genre to the elements of the given genreTable
    for (int i = 0; i < 16; i++) {
        if (strcmp(genre, genreTable[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void insert(VirtualHeap *VH, Song song) {
    int index = hash(song.genre);
    if (index == -1) return;
    
    if (strcmp(VH->H[index].elem.genre, "Empty") == 0 || strcmp(VH->H[index].elem.genre, "Deleted") == 0) {
        //normal insertion
        VH->H[index].elem = song;
        VH->H[index].next = -1;
        return;
    }
    
    int *trav = &VH->H[index].next;
    while (*trav != -1) {
        trav = &VH->H[*trav].next;
    }
    
    if (VH->avail != -1) {
        int newNode = VH->avail;
        VH->avail = VH->H[newNode].next;
        VH->H[newNode].elem = song;
        VH->H[newNode].next = -1;
        *trav = newNode;
    } else {
        printf("No available space to insert song: %s\n", song.songName);
    }
}

void deleteMember(VirtualHeap *VH, Song song) {
    int index = hash(song.genre);
    if (index == -1) return;
    
    //case 1: song is directly at the primary index
    if (strcmp(VH->H[index].elem.genre, song.genre) == 0 && strcmp(VH->H[index].elem.songName, song.songName) == 0) {
        if (VH->H[index].next != -1) {
            int nextNode = VH->H[index].next;
            VH->H[index].elem = VH->H[nextNode].elem;
            VH->H[index].next = VH->H[nextNode].next;
            VH->H[nextNode].next = VH->avail;
            VH->avail = nextNode; 
        } else {
            strcpy(VH->H[index].elem.genre, "Deleted");
            VH->H[index].elem.songName[0] = '\0';
            VH->H[index].elem.singer[0] = '\0';
            VH->H[index].next = -1;
        }
        return;
    }
    //case 2: song might be in the secondary storage
    int prev = index;
    int curr = VH->H[index].next;
    while (curr != -1) {
        if (strcmp(VH->H[curr].elem.songName, song.songName) == 0 && strcmp(VH->H[curr].elem.genre, song.genre) == 0) {
            VH->H[prev].next = VH->H[curr].next;
            VH->H[curr].next = VH->avail;
            VH->avail = curr;
            return;
        }
        prev = curr;
        curr = VH->H[curr].next;
    }
}


int search(VirtualHeap VH, Song song) {
    int index = hash(song.genre);
    if (index == -1) return 0;
    
    if (strcmp(VH.H[index].elem.songName, song.songName) == 0 && strcmp(VH.H[index].elem.genre, song.genre) == 0) {
        return 1;
    }
    
    int curr = VH.H[index].next;
    while (curr != -1) {
        if (strcmp(VH.H[curr].elem.songName, song.songName) == 0 && strcmp(VH.H[curr].elem.genre, song.genre) == 0) {
            return 1;
        }
        curr = VH.H[curr].next;
    }
    return 0;
}