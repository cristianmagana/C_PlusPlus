// adds renters to renters array 
			Renters[numberOfRentedCopies] = rentee;
			numberOfRentedCopies++;

			// need to sort renters array
			// Bubble Sorted by: 
			//    1. Renter.getRenterFirstName()
			//    2. Renter.getRenterLastName()
			//    3. Renter.getRenterID()

			Renter temp;
			for (int i = 1; i < numberOfRentedCopies; i++)
			{
				for (int j = 0; j < numberOfRentedCopies - i; j++)
				{
					if (Renters[j].getRenterFirstName() > Renters[j + 1].getRenterFirstName())
					{
						temp = Renters[j];
						Renters[j] = Renters[j + 1];
						Renters[j + 1] = temp;
					}
					if (Renters[j].getRenterFirstName() == Renters[j + 1].getRenterFirstName())
					{
						if (Renters[j].getRenterLastName() > Renters[j + 1].getRenterLastName())
						{
							temp = Renters[j];
							Renters[j] = Renters[j + 1];
							Renters[j + 1] = temp;
						}
					}
					if (Renters[j].getRenterFirstName() == Renters[j + 1].getRenterFirstName() && Renters[j].getRenterLastName() == Renters[j + 1].getRenterLastName())
					{
						if (Renters[j].getRenterID() > Renters[j + 1].getRenterID())
						{
							temp = Renters[j];
							Renters[j] = Renters[j + 1];
							Renters[j + 1] = temp;
						}
					}
				}
			}

	}
