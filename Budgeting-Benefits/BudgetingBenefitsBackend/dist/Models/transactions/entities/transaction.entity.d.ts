import { User } from '../../user/entities/user.entity';
export declare class Transaction {
    id: number;
    userId: number;
    user: User;
    category: string;
    date: Date;
    amount: number;
}
