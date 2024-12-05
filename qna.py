import wikipedia

while True:
    # Ask the user for a question
    question = input("Ask a question or type 'n' to quit: ")

    # Check if the user wants to exit
    if question.lower() == 'n':
        print("Exiting the program.")
        break

    # Ask for the number of sentences
    try:
        sentences = int(input("Enter the number of sentences for the summary: "))
    except ValueError:
        print("Please enter a valid number for sentences.\n")
        continue

    try:
        # Get a summary from Wikipedia for the question
        answer = wikipedia.summary(question, sentences=sentences)
        print(f"Answer: {answer}\n")
    except wikipedia.exceptions.DisambiguationError as e:
        print(f"Ambiguous question. Please be more specific. Possible options: {e.options}\n")
    except wikipedia.exceptions.HTTPTimeoutError:
        print("Request timed out. Please try again later.\n")
    except wikipedia.exceptions.RedirectError:
        print("The page has been redirected. Please try again.\n")
    except wikipedia.exceptions.PageError:
        print("Sorry, no information found for that question.\n")
