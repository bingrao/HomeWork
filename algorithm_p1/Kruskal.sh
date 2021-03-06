#!/usr/bin/env bash

PWD=`pwd`
INPUT=${PWD}/input/adjacency-list.txt
MAINCLASS=org.ucf.java.Kruskal.KruskalMain
mvn compile
mvn exec:java -Dexec.mainClass="${MAINCLASS}" -Dexec.args="${INPUT}"
mvn clean