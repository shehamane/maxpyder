package main

import (
	"fmt"
	"html/template"
	"net/http"
	"os"
)

func WorkDir() {
	err := os.Chdir("/home/highone/maxpyder/app/backend/")
	cwd, _ := os.Getwd()

	fmt.Println("err: ", err, "cwd: ", cwd)
}

func indexHandler(w http.ResponseWriter, r *http.Request) {
	tpl := template.Must(template.ParseFiles("templates/index.html"))
	tpl.Execute(w, nil)
}

func main() {

	WorkDir()

	/*CurDir, err := os.Getwd()
	if err != nil {
		panic(err)
	} else {
		fmt.Println("Current working directory: ", CurDir)
	}*/

	port := os.Getenv("PORT")
	if port == "" {
		port = "3000"
	}

	mux := http.NewServeMux()

	mux.HandleFunc("/", indexHandler)
	http.ListenAndServe(":"+port, mux)
}
