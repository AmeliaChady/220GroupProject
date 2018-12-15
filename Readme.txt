=========================================
International Phonetics Alphabet Helper
Readme
Amelia Chady
=========================================

=== Tutorial ===
This is a quick tutorial to load and run a quiz
 1. Open the program
 2. You should now be in the Main Menu. To load a quiz, it
   must be within the same directory as the .exe or .app.
   The command to load is
     load <your file name>
   Note: Quizzes are only stored as .csv files, so you do not
   need to add the file extension.
 3. Once you have loaded your file, you can start the quiz in multiple ways.
   The first way is 'preset', which goes through every word in the file.
   The second way is 'random', which randomly picks 10 words from the file.
   The third way is 'random <some number>', which uses your inputted number
   for the amount to pick.
   The command to start is
     start <preset/random> <for random only, some number>
 4. You should now be inside of the quiz. You can answer the question by
   inputting the number representing that answer.

Good Luck!

=== Making Quizzes ===
This is a tutorial for making quizzes for the program
 1. Create a .csv file to put your words in. Using a program like Microsoft Excel
  or Google Sheets is recommended
 2. In the first column, put all of your words as <spelling> in ASCii formatting
 3. In the second column, put all of you words phonetic transcriptions, in ASCii
  formatting (as stated in the next section.
    a. There is an adjoining program that will take your Unicode phonetic
     transcription and format it correctly
 4. Make sure the file is then placed the same directory as the .exe or app
 5. You can then load the file within the main program by doing
      load <your file name>

-- Unicode to ASCii Conversions --
- Consonants -
 p -> p   |  v -> v   |  s -> s   |  ʤ -> .Z  |  k -> k
 b -> b   |  θ -> T   |  z -> z   |  ʃ -> S   |  g -> g
 m -> m   |  ð -> D   |  n -> n   |  ʒ -> Z   |  ŋ -> N
 w -> .w  |  t -> t   |  l -> l   |  r -> R   |  h -> h
 f -> f   |  d -> d   |  ʧ -> .S  |  j -> j   |  ɾ -> r

- Vowels -
 i -> i   |  ɛ -> E   |  u -> u   |  ʌ -> ^   |  y -> y
 ɪ -> I   |  æ -> &   |  ʊ -> U   |  ɔ -> O   |
 e -> e   |  ə -> )   |  o -> o   |  ɑ -> A   |

- Others -
H -> ʰ  | Aspiration
~ -> ̃   | Nazalization. Must be in-front of the letter.
