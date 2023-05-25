#include <stdio.h>

// This function prints the welcome message.
void welcome() {
  printf("Welcome to the Text-Based Adventure Game!\n");
  printf("You are standing in a dark room. There is a door to the north and a door to the south.\n");
}

// This function prints the room description.
void print_room_description(int room_number) {
  switch (room_number) {
    case 1:
      printf("You are in a dark room. There is a door to the north and a door to the south.\n");
      break;
    case 2:
      printf("You are in a bright room. There is a table in the center of the room with a book on it.\n");
      break;
    case 3:
      printf("You are in a dark cave. There is a dragon sleeping in the corner.\n");
      break;
  }
}

// This function prints the list of possible actions.
void print_actions() {
  printf("What do you want to do?\n");
  printf("* Go north\n");
  printf("* Go south\n");
  printf("* Look around\n");
  printf("* Read the book\n");
  printf("* Fight the dragon\n");
}

// This function handles the user input.
void handle_input(int room_number) {
  char input[100];
  fgets(input, 100, stdin);

  // Remove the newline character from the end of the input.
  input[strlen(input) - 1] = '\0';

  // Check the user input.
  if (strcmp(input, "go north") == 0) {
    if (room_number == 1) {
      room_number = 2;
    } else {
      printf("You can't go that way.\n");
    }
  } else if (strcmp(input, "go south") == 0) {
    if (room_number == 2) {
      room_number = 1;
    } else {
      printf("You can't go that way.\n");
    }
  } else if (strcmp(input, "look around") == 0) {
    print_room_description(room_number);
  } else if (strcmp(input, "read the book") == 0) {
    if (room_number == 2) {
      printf("The book tells you how to defeat the dragon.\n");
    } else {
      printf("There is no book here.\n");
    }
  } else if (strcmp(input, "fight the dragon") == 0) {
    if (room_number == 3) {
      if (rand() % 2 == 0) {
        printf("You defeat the dragon!\n");
      } else {
        printf("The dragon defeats you!\n");
      }
    } else {
      printf("There is no dragon here.\n");
    }
  } else {
    printf("I don't understand.\n");
  }
}

// This is the main function.
int main() {
  welcome();

  // Start the game loop.
  int room_number = 1;
  while (1) {
    print_room_description(room_number);
    print_actions();
    handle_input(room_number);

    // Check if the user has won the game.
    if (room_number == 3 && (rand() % 2 == 0)) {
      printf("Congratulations! You have won the game!\n");
      break;
    }
  }

  return 0;
}
