import { TransactionsService } from './transactions.service';
import { CreateTransactionDto } from './dto/create-transaction.dto';
import { UpdateTransactionDto } from './dto/update-transaction.dto';
export declare class TransactionsController {
    private readonly transactionsService;
    constructor(transactionsService: TransactionsService);
    create(createTransactionDto: CreateTransactionDto): Promise<import("./entities/transaction.entity").Transaction>;
    findAll(): void;
    findOne(identifier: any): Promise<{
        id: number;
        category: string;
        date: Date;
        amount: number;
    }>;
    update(id: string, updateTransactionDto: UpdateTransactionDto): Promise<import("./entities/transaction.entity").Transaction>;
    remove(id: string): Promise<void>;
}
