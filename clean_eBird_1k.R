eBird_1k <- read_csv("~/Desktop/CS180/cs180-21-taso6/eBird_1k.csv")
colnames(eBird_1k)
eBird_1k.1 <- eBird_1k[,c(1:2,7:8,17,19,25,28,30)]
colnames(eBird_1k.1) <- c("XCord", "YCord", "commonName", "scientificName", "State", "County", "Locality", "observationDate", "userID")
write.csv(eBird_1k.1, file = "~/eBird_1k_cleaned.csv")
