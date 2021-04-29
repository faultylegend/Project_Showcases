import requests

def show_title():
    print("My Recipes Program")
    print()

def show_menu():
    print("COMMAND MENU")
    print("1 - List all Categories")
    print("2 - List all Meals for a Category")
    print("3 - Search Meal by Name")
    print("4 - Random Meal")
    print("5 - List all Areas")
    print("6 - Search Meals by Area")
    print("7 - Menu")
    print("0 - Exit the program")
    print()

def list_categories(categories):
    print("CATEGORIES\n")
    for i in range(len(categories)):
        category = categories[i]
        print(category.get_category())
    print()

def list_areas(areas):
    print("AREAS\n")
    for i in range(len(areas)):
        area = areas[i]
        print(area.get_category())
    print()

def list_meals_by_category(category, meals):
    print()
    print(category.upper() + " MEALS\n")
    for i in range(len(meals)):
        meal = meals[i]
        print(meal.get_meal())
    print()

def search_category(categories):
    lookup = input("Enter a Category: ")
    found = False

    for i in range(len(categories)):
        category = categories[i]
        if category.get_category().lower() == lookup.lower():
            found = True
            break
    if found:
        meals = requests.get_meals_by_category(lookup)
        list_meals_by_category(lookup, meals)
    else:
        print("Invalid Category, please try again.")

def search_area(areas):
    lookup = input("Enter an Area: ")
    found = False

    for i in range(len(areas)):
        area = areas[i]
        if area.get_category().lower() == lookup.lower():
            found = True
            break
    if found:
        meals = requests.get_meals_by_area(lookup)
        list_meals_by_category(lookup, meals)
    else:
        print("Invalid Area, please try again.")

def display_meal(recipe,meal):
    print()
    print("Recipe:",recipe.get_meal())
    print()
    print("Instructions:",recipe.get_instructions())
    print("\nIngredients:\n")
    measures = requests.get_measures(meal)
    ingredients = requests.get_ingredient(meal)
    for i in range(len(ingredients)):
        measure = measures[i]
        ingredient = ingredients[i]
        print(ingredient.get_ingredient() + " " + measure.get_measure())
    print()

def search_meal_name():
    lookup = input("Enter Meal Name: ")
    meal = requests.get_meal_by_name(lookup)
    if meal:
        display_meal(meal,lookup)
    else:
        print("A recipe for this meal was not found")

def random():
    meal_name = requests.get_random().get_rand()
    meal = requests.get_meal_by_name(meal_name)
    display_meal(meal,meal_name)

def main():
    show_title()
    show_menu()

    categories = requests.get_categories()
    areas = requests.get_areas()

    while True:
        command = input("Command: ")
        print()
        if command == "0":
            break
        elif command == "1":
            list_categories(categories)
        elif command == "2":
            search_category(categories)
        elif command == "3":
            search_meal_name()
        elif command == "4":
            print("A Random Meal was Selected for You!\n")
            random()
        elif command == "5":
            list_areas(areas)
        elif command == "6":
            search_area(areas)
        elif command == "7":
            show_menu()
        else:
            print("not a valid command. Please try again.\n")

if __name__ == "__main__":
    main()