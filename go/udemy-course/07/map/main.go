package main

import (
	"log"
	"os"
	"text/template"
)

var tpl *template.Template

func init() {
	tpl = template.Must(template.ParseGlob("tpl.gohtml"))
}

func main() {
	sages := map[string]string{
		"India":    "Ghandi",
		"USA":      "MLK",
		"Meditate": "Buddha",
		"Love":     "Jesus",
		"Prophet":  "Muhhamad",
	}

	err := tpl.ExecuteTemplate(os.Stdout, "tpl.gohtml", sages)
	if err != nil {
		log.Fatalln(err)
	}
}
