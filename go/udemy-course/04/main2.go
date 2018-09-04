package main

import (
	"log"
	"os"
	"text/template"
)

func secondmain() {
	tpl, err := template.ParseFiles("template.gohtml")

	if err != nil {
		log.Fatalln(err)
	}

	nf, err := os.Create("index.html")
	if err != nil {
		log.Fatalln(err)
	}
	defer nf.Close()

	err = tpl.Execute(nf, nil)
	if err != nil {
		log.Fatalln(err)
	}
}
