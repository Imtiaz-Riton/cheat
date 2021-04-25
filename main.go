package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"os"

	_ "github.com/lib/pq"

	"github.com/gorilla/mux"
	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

type Person struct {
	gorm.Model

	Name  string
	Email string `Email:"unique_index"`
	Books []Book
}

type Book struct {
	gorm.Model
	Title      string
	Author     string
	CallNumber int `sql:"unique_index"`
	PersonID   int
}

var (
	person = &Person{Name: "Riton", Email: "imtiaz@gmail.com"}
	books  = []Book{
		{Title: "hello from", Author: "Imtiaz", CallNumber: 123, PersonID: 1},
		{Title: "hello from1", Author: "Imtiaz2", CallNumber: 1234, PersonID: 2},
	}
)

var db *gorm.DB
var err error

func main() {

	host := os.Getenv("HOST")
	dbPort := os.Getenv("DBPORT")
	user := os.Getenv("USER")
	dbName := os.Getenv("NAME")
	password := os.Getenv("PASSWORD")
	dbURI := fmt.Sprintf("host=%s user=%s password=%s dbname=%s port=%s sslmode=disable TimeZone=Asia/Shanghai",
		host, user, password, dbName, dbPort)
	db, err = gorm.Open(postgres.Open(dbURI), &gorm.Config{})
	if err != nil {
		panic(err)
	} else {
		fmt.Println("successfully connected")
	}
	db.AutoMigrate(&Person{})
	db.AutoMigrate(&Book{})
	db.Create(person)
	for idx := range books {
		db.Create(&books[idx])
	}
	handleRequests()
}

func handleRequests() {
	router := mux.NewRouter().StrictSlash(true)
	router.HandleFunc("/", homePage)
	router.HandleFunc("/people", getPeople)
	log.Fatal(http.ListenAndServe(":8080", router))
}

func homePage(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "welcome to home page!")
}
func getPeople(w http.ResponseWriter, r *http.Request) {
	var person []Person
	db.Find(&person)
	json.NewEncoder(w).Encode(&person)
}
