from urllib import request, parse
import json
from objects import Category, Meal, Recipe, Measure, Ingredients, Random

def get_categories():
    url = "https://www.themealdb.com/api/json/v1/1/list.php?c=list"
    f = request.urlopen(url)
    categories = []

    try:
        data = json.loads(f.read().decode("utf-8"))
        for category_data in data["meals"]:
            category = Category(category_data["strCategory"])
            categories.append(category)
    except(ValueError, KeyError, TypeError):
        print("JSON format error")

    return categories

def get_areas():
    url = "https://www.themealdb.com/api/json/v1/1/list.php?a=list"
    f = request.urlopen(url)
    areas = []

    try:
        data = json.loads(f.read().decode("utf-8"))
        for category_data in data["meals"]:
            category = Category(category_data["strArea"])
            areas.append(category)
    except(ValueError, KeyError, TypeError):
        print("JSON format error")

    return areas

def get_meals_by_category(category):
    url = "https://www.themealdb.com/api/json/v1/1/filter.php?c=" + category
    f = request.urlopen(url)
    meals = []

    try:
        data = json.loads(f.read().decode("utf-8"))
        for meal_data in data["meals"]:
            category = Meal(meal_data["idMeal"], meal_data["strMeal"], meal_data["strMealThumb"])
            meals.append(category)
    except(ValueError, KeyError, TypeError):
        print("JSON format error")
    
    return meals

def get_meals_by_area(area):
    url = "https://www.themealdb.com/api/json/v1/1/filter.php?a=" + area
    f = request.urlopen(url)
    meals = []

    try:
        data = json.loads(f.read().decode("utf-8"))
        for meal_data in data["meals"]:
            category = Meal(meal_data["idMeal"], meal_data["strMeal"], meal_data["strMealThumb"])
            meals.append(category)
    except(ValueError, KeyError, TypeError):
        print("JSON format error")
    
    return meals

def get_meal_by_name(meal):
    url = "https://www.themealdb.com/api/json/v1/1/search.php?s=" + parse.quote(meal)
    f = request.urlopen(url)
    recipe = None

    try:
        data = json.loads(f.read().decode("utf-8"))
        for recipe_data in data["meals"]:
            recipe = Recipe(recipe_data["idMeal"], recipe_data["strMeal"], recipe_data["strCategory"], recipe_data["strInstructions"], recipe_data["strMealThumb"])
    except(ValueError, KeyError, TypeError):
        print("JSON format error")
    return recipe

def get_measures(meal):
    url = "https://www.themealdb.com/api/json/v1/1/search.php?s=" + parse.quote(meal)
    f = request.urlopen(url)
    measures = []

    try:
        data = json.loads(f.read().decode("utf-8"))
        for measure_data in data["meals"]:
            for i in range(1,21):
                if measure_data["strMeasure" + str(i)] == "":
                    break
                measure = Measure(measure_data["strMeasure" + str(i)])
                measures.append(measure)
    except(ValueError, KeyError, TypeError):
        print("JSON format error")

    return measures

def get_ingredient(meal):
    url = "https://www.themealdb.com/api/json/v1/1/search.php?s=" + parse.quote(meal)
    f = request.urlopen(url)  
    ingredients = []
    try:
        data = json.loads(f.read().decode("utf-8"))
        for ingredient_data in data["meals"]:
            for i in range(1,21):
                if ingredient_data["strIngredient" + str(i)] == "":
                    break
                ingredient = Ingredients(ingredient_data["strIngredient" + str(i)])
                ingredients.append(ingredient)
    except(ValueError, KeyError, TypeError):
        print("JSON format error")
    return ingredients

def get_random():
    url = "https://www.themealdb.com/api/json/v1/1/random.php"
    f = request.urlopen(url)
    random = None
    try:
        data = json.loads(f.read().decode("utf-8"))
        for random_data in data["meals"]:
            random = Random(random_data["strMeal"])

    except(ValueError, KeyError, TypeError):
        print("JSON format error")
    return random